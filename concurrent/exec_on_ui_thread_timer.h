#pragma once

#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <thread>


namespace ExecOnUiThreadTimer
{
	int main()
	{
		int argc = 0;
		QCoreApplication a(argc, Q_NULLPTR);
		QThread* mainThread = QThread::currentThread();

		QThread thread;
		QObject::connect(&thread, &QThread::started, [&]()
		{
			bool isMainThread = (mainThread == QThread::currentThread());
			qDebug() << "I should be inside the Background thread; "
				"Is this the main thread? " << isMainThread;

			if (!isMainThread)
				qDebug() << "Cool I really like being on the background thread\n\n";


			QTimer::singleShot(0, qApp, [&]()
			{
				isMainThread = (mainThread == QThread::currentThread());
				// invoke on the main thread
				qDebug() << "I should be inside the Main thread; "
					"Is this the main thread? " << isMainThread;

				if (isMainThread)
					qDebug() << "Cool I really like being on the main thread";
			});
		});

		thread.start();
		return a.exec();
	}
}
