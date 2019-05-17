#pragma once

#include <QtConcurrent/QtConcurrent>
/*
namespace QtConcurrentRunDemo
{
	class VerySlowRunner : public QObject
	{
	Q_OBJECT
	public:
		VerySlowRunner() : QObject(Q_NULLPTR)
		{
		}

		void run()
		{
			QtConcurrent::run(this, &VerySlowRunner::runInternal);
		}


		void runInternal()
		{
		}
	};

	void main()
	{
		VerySlowRunner runner;
		QtConcurrent::run(runner, &VerySlowRunner::run);
	}
}
*/