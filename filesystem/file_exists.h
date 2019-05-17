#pragma once

#include <QFileInfo>
#include <QDebug>

namespace CheckFileExists
{
	inline void main()
	{
		const QString filePath("C:\\Windows\\System32\\calc.exe");
		QFileInfo file(filePath);

		// If the file exists and it is a file(it could be a directory, Symlink, etc)
		if (file.exists() && file.isFile())
			qDebug() << "Yes, that file exists";
		else
			qDebug() << "Nop, that file does not exists";
	}
}
