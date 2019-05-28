#pragma once
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

namespace ConnectQOverload
{
	void main()
	{
		int argc = 0;
		QCoreApplication app(argc, Q_NULLPTR);

		QProcess process;
		process.setReadChannel(QProcess::StandardOutput);
		process.setReadChannelMode(QProcess::MergedChannels);

		// Caption means process name, we want to output everything to stdout because
		// we are hooked into the process's stdout
		process.start("ping localhost");

		// There are two signals called finished:
		// 1 - void QProcess::finished(int exitCode);
		// 2 - void QProcess::finished(int exitCode, QProcess::ExitStatus exitStatus);
		// To break this ambiguity we use QOverload, available since Qt 5
		QObject::connect(&process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
		                 [&](int exitCode, QProcess::ExitStatus status)
		                 {
			                 if (status == QProcess::NormalExit)
			                 {
				                 qDebug() << "Normal exit for Process: " << process.program();
				                 qDebug() << "Exit code: " << exitCode;
			                 }
			                 else if (status == QProcess::CrashExit)
			                 {
				                 qWarning() << "Process crashed! Program: " << process.program();
				                 qDebug() << "Exit code: " << exitCode;
				                 // process->start(process.program());
			                 }

							 qDebug().noquote() << QString(process.readAll());
			                 qApp->quit();
		                 });

		QObject::connect(&process, &QProcess::errorOccurred, [&process](QProcess::ProcessError error)
		{
			// TODO: parse the ProcessError enum and print something meaningful
			qDebug() << "An Error occurred: " << error;
			qApp->quit();
		});

		app.exec();
	}
}
