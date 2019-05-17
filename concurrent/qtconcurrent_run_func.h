#pragma once
#include <QtConcurrent/QtConcurrentRun>

namespace QtConcurrentRunFunc
{
	void run()
	{
	}

	int main()
	{
		QFuture<void> future = QtConcurrent::run(run);
		future.waitForFinished();
		return 0;
	}
}
