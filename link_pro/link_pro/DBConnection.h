#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRelationalTableModel>
#include <QMap>

class DBConnection : public QObject
{
public:

	Q_GLOBAL_STATIC(DBConnection, Singleton)

	DBConnection();
	~DBConnection();
	
	bool init();
	QSqlDatabase* getDBCon();
	QSqlRelationalTableModel *getModel(const QString&);
private:
	QSqlDatabase mDB;
	QMap<QString, QSqlRelationalTableModel*> mModelMap;

};
#endif DBCONNECTION_H