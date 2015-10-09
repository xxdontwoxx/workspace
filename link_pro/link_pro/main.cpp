#include "link_pro.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	link_pro w;
	w.show();
	return a.exec();
}
