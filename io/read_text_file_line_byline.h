#pragma once
#include <QFile>
#include <QDebug>

namespace ReadTextFileLineByLine
{
	void main()
	{
		// Adjust the file path as you need
		QFile file("./README.md");
		if (!file.open(QIODevice::ReadOnly))
		{
			qCritical() << "Could not open the file, exiting";
			return;
		}

		QTextStream in(&file);
		
		while (!in.atEnd())
		{
			QString line = in.readLine();
			qDebug().noquote() << line;
		}
		file.close();
	}
}
