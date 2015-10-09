#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QMap>

class DBConnection : public QObject
{
public:

	Q_GLOBAL_STATIC(DBConnection, Singleton)

	DBConnection();
	~DBConnection();
	
	bool init();
	QSqlDatabase* getDBCon();
	QSqlTableModel *getModel(const QString&);
private:
	QSqlDatabase mDB;
	QMap<QString, QSqlTableModel*> mModelMap;

};
#endif DBCONNECTION_H