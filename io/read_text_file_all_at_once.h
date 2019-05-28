#pragma once
#include <QFile>
#include <QDebug>

namespace ReadTextFileAllAtOnce
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

		const QString contents = in.readAll();
		qDebug().noquote() << contents;

		file.close();
	}
}
