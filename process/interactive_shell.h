#pragma once
#include <QProcess>
#include <QString>
#include <QStringList>
#include "Windows.h"
#include <QDebug>
#include <iostream>

namespace InteractiveShell
{
	QString getProgramPath()
	{
#ifdef Q_OS_WIN
		return "cmd.exe";
#else
		const QFileInfo shell("/bin/sh");
		if (!shell.exists())
		{
			const QFileInfo bash("/bin/bash");
			if (!bash.exists())
			{
				qDebug() << "shell not found, please write down the shell path before running this snippet";
				return "";
			}

			return bash.absoluteFilePath();
		}

		return shell.absoluteFilePath();
#endif
	}

	static int main()
	{
		int argc = 0;
		const QCoreApplication a(argc, Q_NULLPTR);

		QProcess process;
		const QString program = getProgramPath();
		if (program.isEmpty())
			return 1;

		process.setProcessChannelMode(QProcess::MergedChannels);

		process.start(program);


		QObject::connect(&process, &QProcess::readyRead, [&process]()
		{
			const QByteArray a = process.readAll();
			qDebug().noquote().nospace() << a;
		});

		// delete process instance when done, and get the exit status to handle errors.
		QObject::connect(&process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
		                 [&](int exitCode, QProcess::ExitStatus /*exitStatus*/)
		                 {
			                 qDebug() << "process exited with code " << exitCode;
		                 });


		char buffer[1024];
		QThread th;

		QObject::connect(&th, &QThread::started, [&]()
		{
			while (true)
			{
				std::cin.getline(buffer, 1024);
				QString bufferStr(buffer);
				process.write((bufferStr + "\r\n").toUtf8());
				process.waitForBytesWritten();

				if (bufferStr == "exit")
				{
					th.exit(0);
					a.exit(0);
					break;
				}
			}
		});


		th.start();


		return a.exec();
	}
}
