#pragma once
#ifndef INVOKE_METHOD_USAGE_H
#define INVOKE_METHOD_USAGE_H
#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QObject>

namespace InvokeMethodUsage
{
	class Worker : public QObject
	{
	Q_OBJECT
	public:

		QThread* mainThread;

		Worker(QThread* mainThread) : QObject(Q_NULLPTR),
		                              mainThread(mainThread)
		{
		}

		void run()
		{
			QThread* currentThread = QThread::currentThread();
			const bool isUiThread = (currentThread == mainThread);
			qDebug() << "run() is executed in the main thread? " << isUiThread;
			qDebug() << "run() Thread Id " << QThread::currentThreadId() << "\n";

			QThread* th = new QThread;
			connect(th, &QThread::started, this, &Worker::executeInBackground, Qt::DirectConnection);
			th->start();
		}


		void executeInBackground()
		{
			QThread* currentThread = QThread::currentThread();
			const bool isUiThread = (currentThread == mainThread);
			qDebug() << "executeInBackground() is executed in the main thread? "
				<< isUiThread;
			qDebug() << "executeInBackground() Thread Id " << QThread::currentThreadId() << "\n";;

			QThread::currentThread()->sleep(2);
			onBackgroundFinished();
		}

		void onBackgroundFinished()
		{
			QThread* currentThread = QThread::currentThread();
			const bool isUiThread = (currentThread == mainThread);

			qDebug() << "onBackgroundFinished() is executed in the main thread? "
				<< isUiThread;
			qDebug() << "onBackgroundFinished() Thread Id " << QThread::currentThreadId();
			// This is useful when you have a method executed in a background thread
			// but you want to update the user interface which should only be updated from UI Thread
			// it happens that this object(Worker) was created in the main thread
			// so it belongs to the Main thread, that means, if we trigger a SLOT through the signal/slot
			// Qt mechanism then the slot will be called in the Main Thread(Because it is owned by the Main Thread,
			// the thread where it was created).
			QMetaObject::invokeMethod(this, // object to trigger
			                          "updateUi", // method Name of the object to be triggered
			                          Qt::QueuedConnection, // type of triggering(other demo explains it)
			                          Q_ARG(QString, "Result"), // args passed
			                          Q_ARG(bool, true)); // args passed
		}

	private slots:
		void updateUi(const QString& argString, bool argBool) const
		{
			QThread* currentThread = QThread::currentThread();
			const bool isUiThread = (currentThread == mainThread);
			qDebug() << "UpdateUi: Is this the main thread? " << isUiThread
				<< "\nUpdateUi() is called in the thread with Id " << QThread::currentThreadId()

				<< "\nArgs received:\n\tArgString: " << argString << "\n\targBool: " << argBool << "\n";
		}

	public:
		static int main()
		{
			int argc = 0;
			QCoreApplication app(argc, Q_NULLPTR);
			QThread* mainThread = QThread::currentThread();
			Worker worker(mainThread);
			worker.run();
			return app.exec();
		}
	};
}
#endif
