#pragma once
#include <QDebug>
#include <QDir>
#include <QFileInfo>

namespace GetAllDrives
{
	void main()
	{
		QDir dir;
		for (const QFileInfo& drive : QDir::drives())
		{
			qDebug() << "Drive " << drive.absolutePath();
		}
	}
}
