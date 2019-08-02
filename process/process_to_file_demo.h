#pragma once
#include <QProcess>
#include <QDebug>

namespace ProcessToFile
{
	static void main()
	{
		QProcess process;
		QFileInfo f("./whoami.txt");

		process.setStandardOutputFile(f.absoluteFilePath(), QIODevice::Append /*Truncate is the default*/);
		process.start("whoami");
		process.waitForFinished();

		qDebug().noquote() << "Done, check its contents in: " << f.absoluteFilePath();
	}
}
