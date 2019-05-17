#pragma once
#include <QCoreApplication>
#include <QThread>
#include <QDebug>

namespace InvokeFuncOnMainThread
{
	int main()
	{
		int argc = 0;
		QCoreApplication app(argc, Q_NULLPTR);
		QThread* mainThread = QThread::currentThread();
		QThread th;
		QObject::connect(&th, &QThread::started, [&]()
		{
			bool isMainThread = (mainThread == QThread::currentThread());
			qDebug() << "I should be inside the Background thread; "
				"Is this the main thread? " << isMainThread;
			if (!isMainThread)
				qDebug() << "Cool I really like being on the background thread\n\n";

			// qApp macro gives us the QApplication instance
			// It is explained on the another snippet
			QMetaObject::invokeMethod(qApp, [&]
			{
				isMainThread = (mainThread == QThread::currentThread());
				// invoke on the main thread
				qDebug() << "I should be inside the Main thread; "
					"Is this the main thread? " << isMainThread;

				if (isMainThread)
					qDebug() << "Cool I really like being on the main thread";
			});
		});
		th.start();
		return app.exec();
	}
}
