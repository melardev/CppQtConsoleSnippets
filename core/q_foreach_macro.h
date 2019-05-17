#pragma once
#include <QDir>
#include <QDebug>

namespace QForeachMacroDemo
{
	void main()
	{
		foreach(const QFileInfo& drive, QDir::drives())
		{
			qDebug() << "Drive : " << drive.absoluteFilePath();
		}
	}
}
