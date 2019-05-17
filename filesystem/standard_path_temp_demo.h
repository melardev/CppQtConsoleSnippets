#pragma once
#include <QString>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>

namespace GetStandardTempPath
{
	inline void main()
	{
		QString tempPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
		if (!tempPath.isEmpty() && QFileInfo(tempPath).isDir())
			qDebug() << "temp file exists " << tempPath;
		else
			qDebug() << "temp file doesn't exists " << tempPath;
	}
}
