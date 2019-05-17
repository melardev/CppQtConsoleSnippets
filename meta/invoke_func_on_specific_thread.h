#pragma once
// invoke on a particular thread
#include <QDebug>
#include <QThread>
#include <QCoreApplication>
#include <QAbstractEventDispatcher>

/// This snippet shows how to run code in any thread you have a reference to.
/// The difference with other invoke_func_on_main_thread is that that approach
/// runs code on the thread that owns the specified object
/// In other words, there we specified the object
/// whereas in this snippet we specify the thread itself
namespace InvokeFuncInSpecificThread
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

			QMetaObject::invokeMethod(
				QAbstractEventDispatcher::instance(mainThread),
				[&]
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
