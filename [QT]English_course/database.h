#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase> 
#include <QtGui/QMessageBox>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/qsqldriver.h>
#include <QtSql/QSqlDriverPlugin>

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <C:\wamp32\bin\mysql\mysql5.5.16\include\mysql.h>

using namespace std;




class database
{
public:
	static bool createConnection()
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("127.0.0.1");
		db.setDatabaseName("qt_tracking");
		db.setUserName("root");
		db.setPassword("");
		if (!db.open()) {
		    QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
			return false;
		}
		return true;
	}

	static MYSQL* connectByC()
	{
	
		MYSQL *con = mysql_init(NULL);
		if(mysql_real_connect(con, "127.0.0.1","root","","qt_tracking",0,NULL,0)== NULL)
		{
			mysql_error(con);
			return NULL;
		}
		else
		{
			return con;
		}		
	}

	static void closeConnectionC(MYSQL *connect)
	{
		mysql_close(connect);
	}
};



#endif