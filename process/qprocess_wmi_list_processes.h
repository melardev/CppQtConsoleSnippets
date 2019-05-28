#pragma once
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

namespace GetProcessListWmic
{
	int main()
	{
		int argc = 0;
		QCoreApplication a(argc, Q_NULLPTR);

		QProcess process;
		process.setReadChannel(QProcess::StandardOutput);
		process.setReadChannelMode(QProcess::MergedChannels);

		// Caption means process name, we want to output everything to stdout because
		// we are hooked into the process's stdout
		process.start("wmic.exe /OUTPUT:STDOUT PROCESS get Caption");
		// process.start("cmd", QStringList() << "/C" << "echo" << "process" << "get" << "caption" << "|" << "wmic");

		process.waitForStarted(1000);
		process.waitForFinished(1000);

		const QByteArray processList = process.readAll();
		qDebug().noquote() << QString::fromUtf8(processList);

		return 0;
	}
}
