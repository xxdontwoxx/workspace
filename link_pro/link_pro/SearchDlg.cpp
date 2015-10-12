#include "SearchDlg.h"
#include <QListWidgetItem>
#include <QRadioButton>
#include <QSqlRecord>
#include <QSqlField>

SearchDlg::SearchDlg( QSqlRelationalTableModel *model, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	mModel = model;
	connect(ui.mBtnOk,SIGNAL(clicked(bool)),this,SLOT(on_ok()));
	connect(ui.mBtnCancel,SIGNAL(clicked(bool)),this,SLOT(on_cancel()));
	for(int i = 0; i < mModel->columnCount(); ++i)
	{
		QString name = mModel->headerData(i, Qt::Horizontal).toString();
		ui.mCmbField->addItem(name);
	}
	QStringList options;
	options<<QString::fromLocal8Bit("=")
		<<QString::fromLocal8Bit(">")
		<<QString::fromLocal8Bit(">=")
		<<QString::fromLocal8Bit("<")
		<<QString::fromLocal8Bit("<=")
		<<QString::fromLocal8Bit("<>")
		<<QString::fromLocal8Bit("like");

	ui.mCmbCondition->addItems(options);
}

SearchDlg::~SearchDlg()
{

}

void SearchDlg::on_ok()
{
	QString field = ui.mCmbField->currentText();
	QString condition = ui.mCmbCondition->currentText();
	QString value = ui.lineEdit->text().trimmed();
	mModel->setFilter(QObject::tr("%1 %2 '%3'").arg(field).arg(condition).arg(value));

	emit accept();
}

void SearchDlg::on_cancel()
{
	emit reject();
}