#pragma once
#include <QDebug>
#include <QStringList>
#include <QDirIterator>


namespace QStringListUsage
{
	void main()
	{
		const QStringList searchedExtensions = QStringList() << "*.cpp" << "*.sln";

		QDirIterator dirIterator("./", searchedExtensions);
		while (dirIterator.hasNext())
		{
			QString codeFile = dirIterator.next();
			qDebug() << "Found " + codeFile;
		}
	}
}
