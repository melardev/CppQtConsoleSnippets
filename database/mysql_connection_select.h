#pragma once
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace MySQLConnectionSelect
{
	int main()
	{
		int argc = 0;
		QCoreApplication a(argc, Q_NULLPTR);

		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("127.0.0.1");
		db.setPort(3306);
		// This corresponds to a database I was using while making
		// My Spring Boot Api Blog app
		db.setDatabaseName("sboot_blog_api");
		db.setUserName("root");
		db.setPassword("root");

		if (db.open())
		{
			qDebug() << "Connected!";
		}
		else
		{
			qDebug() << "Failed to connect.";
			return 0;
		}

		const QString sqlQuery = "SELECT * from articles";
		QSqlQuery query(db);
		if (query.exec(sqlQuery))
		{
			while (query.next())
			{
				const QString articleTitle = query.value("title").toString();
				const QString articleBody = query.value("body").toString();
				qDebug() << "Title: " << articleTitle;
				qDebug() << "Body:\n " << articleBody;
			}
		}

		return a.exec();
	}
}
