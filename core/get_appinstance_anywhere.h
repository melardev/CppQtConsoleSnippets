#pragma once
#include <QCoreApplication>
#include <QDebug>

// Sometimes you may want to create your own macro tot return your own class, or just use the one provided
// by QT and then cast it to yours example
// #define qApp (MyAppClass::instance())

namespace GetAppInstanceDemo
{
	void main(int argc, char** argv)
	{
		QCoreApplication app(argc, argv);
		qDebug() << "Application name: " << qApp->applicationName();
		qDebug() << "Class Name: " << qApp->metaObject()->className();
		app.exec();
	}
}
