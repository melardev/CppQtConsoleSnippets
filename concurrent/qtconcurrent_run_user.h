#pragma once
#include <QtConcurrentRun>

namespace QtConcurrentRunUsage
{
	class Runner
	{
	public:
		void run()
		{
			qDebug() << "Runner::run() is called";
		}
	};

	int main()
	{
		int argc = 0;
		QCoreApplication app(argc, Q_NULLPTR);
		Runner a;

		QFuture<void> myFuture = QtConcurrent::run(&a, &Runner::run);
		myFuture.waitForFinished();

		auto myFuture2 = QtConcurrent::run(&a, static_cast<void(Runner::*)()>(&Runner::run));
		myFuture2.waitForFinished();

		return app.exec();
	}
}
