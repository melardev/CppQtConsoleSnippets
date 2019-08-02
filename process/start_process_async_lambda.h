#pragma once
#include <QProcess>
#include <QDebug>

namespace StartProcessAsyncLambda
{
	class ProcessLauncher : public QObject
	{
	Q_OBJECT
	public:
		QString processName;

		ProcessLauncher(QString processName) : QObject(Q_NULLPTR), processName(processName)
		{
		}

		void run()
		{
			QProcess* process = new QProcess(this);

			process->start(processName);

			connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
			        [this](int exit_code, QProcess::ExitStatus status)
			        {
				        qDebug() << processName << "Exit status code " << status << "Exit code " << exit_code;
			        });

			// Refresher on lambda expressions, we can pass everything as a reference, passing this is redundant here
			connect(process, &QProcess::errorOccurred, [&, this](QProcess::ProcessError error)
			{
				qDebug() << processName << process->arguments() << "Error" << error;
			});

			char buffer[1024];
			connect(process, &QProcess::readyRead, [&, this]()
			{
				qint64 read = 0;

				// Read everything available at this moment in time in the internal QIODevice buffer(QProcess extends QIODevice)
				// Or use .readAll() instead
				do
				{
					// But, what about future data that is not yet retrieved?, we don't care, Qt will call this callback again
					// so we don't have to make sure to wait new data here, instead we read and we exit this loop. The next time we have
					// more data, this callback will be called
					read = process->read(buffer, 1023);
					buffer[read] = 0x00; // Null byte terminator
					qDebug().noquote().nospace() << buffer;
				}
				while (read > 0);
			});

			// https://doc.qt.io/qt-5/qprocess.html#waitForFinished
			// It will wait by default 6000 msec, return true if finished, return false if not
			process->waitForFinished(6000);
		}
	};

	static void main()
	{
#ifdef Q_OS_WIN
		ProcessLauncher launcher("ping google.com");
#else
		ProcessLauncher launcher("ping -n 5 google.com");
#endif
		launcher.run();
	}
}
