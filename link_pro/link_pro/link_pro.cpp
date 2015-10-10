#include "link_pro.h"
#include "dbview.h"

link_pro::link_pro(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	DBConnection::Singleton()->init();
}

link_pro::~link_pro()
{

}

void link_pro::on_dbaction_triggered()
{
	DBView *view = new DBView();
	view->show();
}