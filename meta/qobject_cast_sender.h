#pragma once
#include <QCoreApplication>
#include <QDebug>
#include <QThread>

namespace QCastObjectSender
{
	class Sender : public QObject
	{
	Q_OBJECT
	public:
		Sender() : QObject(Q_NULLPTR)
		{
		}

		void sayWhoYouAre()
		{
			qDebug() << "You catched me!! I am the Sender";
		}

		void doJob()
		{
			// some work.
			QThread::sleep(1);
			// then finished
			int resultOfReallyHeavyTask = 20;
			emit signalFinishedJob(20);
		}

	signals:
		void signalFinishedJob(int);
	private:
	};

	class Receiver : public QObject
	{
	Q_OBJECT
	public:
		Receiver() : QObject(Q_NULLPTR)
		{
		}

	public slots:
		void onReceived(int resultOfReallyHeavyTask)
		{
			// This is really useful in some scenarios such as in networking
			// you can get who is the client who emitted a signal to your server
			// QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
			Sender* sender = qobject_cast<Sender*>(QObject::sender());
			sender->sayWhoYouAre();
		}
	};

	class Launcher
	{
	public:
		static int main()
		{
			int argc = 0;
			QCoreApplication app(argc, Q_NULLPTR);
			Sender sender;
			Receiver receiver;
			QObject::connect(&sender, &Sender::signalFinishedJob, &receiver, &Receiver::onReceived);

			sender.doJob();
			return app.exec();
		}
	};
}
