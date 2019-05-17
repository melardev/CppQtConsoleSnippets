#pragma once
#include <QString>
#include <QFileInfo>
#include <QDebug>

namespace GetFileSizeQFileInfo
{
	void main()
	{
		const QString fileLocation("C:\\Windows\\system32\\calc.exe");
		QFileInfo file(fileLocation);
		if (file.exists())
			qDebug() << "calc.exe has a size of" << file.size();
		else
			qCritical() << "calc.exe does not exist";
	}
}
