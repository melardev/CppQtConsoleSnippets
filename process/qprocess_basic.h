#pragma once
#include <QProcess>
#include <QDebug>

namespace QProcessBasicsDemo
{
	static int main()
	{
		QProcess process;
		const QString exePath("ping");
#ifdef Q_OS_WIN
		process.start(exePath, {"localhost"});
#else
		process.start(exePath, { "-n", "5", "localhostt" });
#endif
		if (!process.waitForFinished())
		{
			qWarning() << QStringLiteral("An error occurred `%1` (%2).")
			              .arg(exePath).arg(process.errorString());
			return false;
		}


		const QByteArray buf(process.readAll());
		const QString processOutput(buf);
		qDebug().noquote() << processOutput;

		return false;
	}
}
