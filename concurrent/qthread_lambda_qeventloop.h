#pragma once
#include <QThread>
#include <QEventLoop>
#include <QDebug>
#include <QCoreApplication>

namespace QThreadLambdaAndQEventLoop
{
	int main()
	{
		int argc = 0;
		QCoreApplication app(argc, Q_NULLPTR);
		QThread thread;
		QEventLoop loop;
		QObject context;
		context.moveToThread(&thread);
		QObject::connect(&thread, &QThread::started, &context, [&]()
		{
			qDebug() << "Performing a heaving work ";
			// Perform some task, let's say it takes 5 seconds
			QThread::sleep(5);
			qDebug() << "Finishing worker thread";
			loop.quit(); // quit the event loop, this emits a finished signal
		});
		thread.start();
		loop.exec(); // Wait until event loop receives a signal of finished
		qDebug() << "We are done waiting the QEventLoop";
		thread.quit();
		thread.wait();

		return app.exec();
	}
}
