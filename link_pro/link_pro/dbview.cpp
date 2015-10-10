#include "dbview.h"
#include "DBConnection.h"

DBView::DBView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	DBConnection *dbc = DBConnection::Singleton();
	foreach(QString tableName, dbc->getModels().keys())
	{
		ui.listWidget->addItem(tableName);
	}
	connect(ui.listWidget, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
		this, SLOT(on_currentItemChanged(QListWidgetItem*, QListWidgetItem*)));
}

DBView::~DBView()
{

}

void DBView::on_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous)
{
	if(previous)
	{
		QString &lastlabel = current->text();
		QSqlRelationalTableModel *lastmodel = DBConnection::Singleton()->getModel(lastlabel);
		lastmodel->submit();
	}
	QString &label = current->text();
	QSqlRelationalTableModel *model = DBConnection::Singleton()->getModel(label);
	model->select();
	QTableView *view = ui.tableView;
	view->setModel(model);
	view->setItemDelegate(new QSqlRelationalDelegate(view));
}

void DBView::closeEvent(QCloseEvent *close)
{
	foreach(QSqlRelationalTableModel* model, DBConnection::Singleton()->getModels().values())
	{
		model->submit();
	}
}