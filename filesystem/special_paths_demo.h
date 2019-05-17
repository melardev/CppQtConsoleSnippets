#pragma once
#include <QDir>
#include <QString>
#include <QDebug>

namespace GetHomePath
{
	int main()
	{
		QDir dir = QDir::homePath();
		const QString qAbsolutePath = dir.absolutePath();

		qDebug() << qAbsolutePath;
		return 0;
	}
}
