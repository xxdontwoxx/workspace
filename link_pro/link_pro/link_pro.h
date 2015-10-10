#ifndef LINK_PRO_H
#define LINK_PRO_H

#include <QtGui/QMainWindow>
#include "ui_link_pro.h"

#include "DBConnection.h"
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QTableView>
#include <QSqlRecord>
#include <QDebug>

class link_pro : public QMainWindow
{
	Q_OBJECT
public:
	link_pro(QWidget *parent = 0, Qt::WFlags flags = 0);
	~link_pro();

private:
	Ui::link_proClass ui;

public slots:
	void on_dbaction_triggered();
};

#endif // LINK_PRO_H
