#pragma once
#include <QDirIterator>
#include <QDebug>


namespace DirRecursiveIteratorDemo
{
	int main()
	{
		QStringList extensionList;
		extensionList << "*.cpp" << "*.h";

		// QDirIterator it("/etc", QDirIterator::Subdirectories);
		QDirIterator dirIterator("./", extensionList, QDir::Files, QDirIterator::Subdirectories);
		while (dirIterator.hasNext())
		{
			QString currentFile = dirIterator.next();
			qDebug() << "Source code file found: " << currentFile;
		}

		return 0;
	}
}
