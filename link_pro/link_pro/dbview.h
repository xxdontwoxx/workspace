#ifndef DBVIEW_H
#define DBVIEW_H

#include <QWidget>
#include "ui_dbview.h"
#include <QSqlRelationalDelegate>

class DBView : public QWidget
{
	Q_OBJECT

public:
	DBView(QWidget *parent = 0);
	~DBView();

private:
	Ui::DBView ui;

public slots:
	void on_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous);
	void closeEvent(QCloseEvent*);

};

#endif // DBVIEW_H
