#include "dbview.h"
#include "DBConnection.h"
#include "SearchDlg.h"

DBView::DBView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//init listWidget
	mDataChanged = false;
	mSearching = false;
	DBConnection *dbc = DBConnection::Singleton();
	foreach(QString tableName, dbc->getModels().keys())
	{
		ui.listWidget->addItem(tableName);
	}
	connect(ui.listWidget, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
		this, SLOT(on_currentItemChanged(QListWidgetItem*, QListWidgetItem*)));

	//init actiongroup
	mActionGroup = new QActionGroup(this);
	mFindAction = mActionGroup->addAction(QIcon(":/Resources/Icons/find.png"),
		QString::fromLocal8Bit("查询"));
	mCloseFindAction = mActionGroup->addAction(QString::fromLocal8Bit("退出查询"));
	mAddAction = mActionGroup->addAction(QIcon(":/Resources/Icons/add.png"),
		QString::fromLocal8Bit("添加"));
	mDeleteAction = mActionGroup->addAction(QIcon(":/Resources/Icons/del.png"),
		QString::fromLocal8Bit("删除"));
	mSaveAction = mActionGroup->addAction(QIcon(":/Resources/Icons/del.png"),
		QString::fromLocal8Bit("提交修改"));
	mRevertAction = mActionGroup->addAction(QIcon(":/Resources/Icons/del.png"),
		QString::fromLocal8Bit("撤销所有修改"));
	connect(mActionGroup,SIGNAL(triggered(QAction *)),this,SLOT(on_actions(QAction*)));

	//init tableview
	connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(on_tableview_doubleclick(const QModelIndex&)));
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
	ui.tableView->addActions(mActionGroup->actions());
	ui.tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

	//set item0 as currentItem
	ui.listWidget->setCurrentItem(ui.listWidget->item(0));
	mCloseFindAction->setEnabled(mSearching);
	mFindAction->setEnabled(!mSearching);
}

DBView::~DBView()
{

}

void DBView::on_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous)
{
	if(previous)
	{
		checkModelSave();
	}
	mDataChanged = false;
	QString &label = current->text();
	QSqlRelationalTableModel *model = DBConnection::Singleton()->getModel(label);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();
	QTableView *view = ui.tableView;
	view->setModel(model);
	view->setItemDelegate(new QSqlRelationalDelegate(view));
}

void DBView::closeEvent(QCloseEvent *close)
{
	checkModelSave();
}
void DBView::on_actions(QAction* action)
{
	if(!action)
	{
		return;
	}
	QSqlRelationalTableModel *curModel = static_cast<QSqlRelationalTableModel *>(ui.tableView->model());
	if(!curModel)
		return;
	if(action == mAddAction)
	{
		int rowNum = curModel->rowCount();
		curModel->insertRow(rowNum);
	}
	else if (action == mDeleteAction)
	{
		QModelIndexList selects = ui.tableView->selectionModel()->selectedRows();
		foreach (QModelIndex index, selects)
		{
			int curRow = index.row();
			curModel->removeRow(curRow);
		}
	}
	else if (action == mFindAction)
	{
		SearchDlg *dlg = new SearchDlg(curModel);
		dlg->exec();
		curModel->select();
		mSearching = true;
		mCloseFindAction->setEnabled(mSearching);
		mFindAction->setEnabled(!mSearching);
		/*QTableView *view = ui.tableView;
		view->setModel(model);
		view->setItemDelegate(new QSqlRelationalDelegate(view));*/
	}
	else if (mCloseFindAction == action) //退出查询
	{
		curModel->setFilter("");
		curModel->select();
		mSearching = false;
		mCloseFindAction->setEnabled(mSearching);
		mFindAction->setEnabled(!mSearching);
		/*QTableView *view = ui.tableView;
		view->setModel(model);
		view->setItemDelegate(new QSqlRelationalDelegate(view));*/
	}
	else if(mSaveAction == action)
	{
		commitData();
	}
	else if(mRevertAction == action)
	{
		revertData();
	}
}

void DBView::on_tableview_doubleclick(const QModelIndex & index)
{
	mDataChanged = true;
}

void DBView::checkModelSave()
{
	QSqlRelationalTableModel *curModel = static_cast<QSqlRelationalTableModel *>(ui.tableView->model());
	if(!curModel)
		return;
	if(mDataChanged)
	{
		int ok = QMessageBox::warning(this,tr("警告"),tr("数据已修改，是否保存"),  
			QMessageBox::Yes,QMessageBox::No);  
		if(ok == QMessageBox::No)  
		{  
			curModel->revertAll();
		}  
		else
		{
			curModel->database().transaction();
			if (curModel->submitAll()) {
				curModel->database().commit();
			} else {
				curModel->database().rollback();
				QMessageBox::warning(this, tr("警告"),
					tr("数据库错误 %1")
					.arg(curModel->lastError().text()));
			}
		}
	}
}

void DBView::commitData()
{
	QSqlRelationalTableModel *curModel = static_cast<QSqlRelationalTableModel *>(ui.tableView->model());
	if(!curModel)
		return;
	curModel->database().transaction();
	if (curModel->submitAll()) {
		curModel->database().commit();
		mDataChanged = false;
	} else {
		curModel->database().rollback();
		QMessageBox::warning(this, tr("警告"),
			tr("数据库错误 %1")
			.arg(curModel->lastError().text()));
	}
}

void DBView::revertData()
{
	QSqlRelationalTableModel *curModel = static_cast<QSqlRelationalTableModel *>(ui.tableView->model());
	if(!curModel)
		return;
	curModel->revertAll();
	mDataChanged = false;
}