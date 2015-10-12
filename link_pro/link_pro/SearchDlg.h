#ifndef SEARCHDLG_H
#define SEARCHDLG_H

#include <QDialog>
#include "ui_SearchDlg.h"
#include <QSqlRelationalTableModel>
class SearchDlg : public QDialog
{
	Q_OBJECT

public:
	SearchDlg(QSqlRelationalTableModel *model, QWidget *parent = 0);
	~SearchDlg();
protected slots:
	void on_ok();
	void on_cancel();

private:
	Ui::SearchDlg ui;
	QSqlRelationalTableModel *mModel;
};

#endif // SEARCHDLG_H
