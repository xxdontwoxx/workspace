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
	bool mDataChanged;
	bool mSearching;

	//actions
	QActionGroup* mActionGroup;
	QAction* mFindAction;
	QAction* mCloseFindAction;
	QAction* mAddAction;
	QAction* mDeleteAction;
	QAction* mSaveAction;
	QAction* mRevertAction;

	void checkModelSave();
	void commitData();
	void revertData();
public slots:
	void on_currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous);
	virtual void closeEvent(QCloseEvent*);
	void on_actions(QAction*);
	void on_tableview_doubleclick(const QModelIndex & index);
};

#endif // DBVIEW_H
