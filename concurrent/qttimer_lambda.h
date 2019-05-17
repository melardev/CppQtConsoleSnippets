#pragma once
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

namespace QTimerLambda
{
	int main()
	{
		int argc = 0;
		QCoreApplication app(argc, Q_NULLPTR);
		QTimer timer;
		/*
		QObject::connect(&timer, &QTimer::timeout, []()
		{
			qDebug() << "Inside timer";
		});
		*/

		timer.singleShot(1000, []()
		{
			qDebug() << "Inside timer";
		});

		return app.exec();
	}
}
