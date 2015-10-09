#include "DBConnection.h"

DBConnection::DBConnection()
{
}

DBConnection::~DBConnection()
{
	
}

bool DBConnection::init()
{
	mDB = QSqlDatabase::addDatabase("QSQLITE");
	mDB.setDatabaseName("test.db");
	if(!mDB.open()){
		QMessageBox::critical(0, "Cannot open database",
			"database open failed", QMessageBox::Cancel);
		return false;
	}
	foreach(QString tableName, mDB.tables())
	{
		QSqlTableModel *temp = new QSqlTableModel(this, mDB);
		temp->setTable(tableName);
		mModelMap.insert(tableName, temp);
	}
	return true;
}

QSqlDatabase *DBConnection::getDBCon()
{
	return &mDB;
}

QSqlTableModel *DBConnection::getModel(const QString &name)
{
	return mModelMap[name];
}