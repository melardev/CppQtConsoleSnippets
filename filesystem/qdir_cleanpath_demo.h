#pragma once

#include <QDir>
#include <QDebug>

namespace GetDirCleanPath
{
	void main()
	{
		qDebug() << QDir::cleanPath("C:\\Windows\\System32");
	}
}
