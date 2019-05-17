#pragma once
#include <QDir>
#include <QDebug>

namespace DirCdCreateDemo
{
	int main()
	{
		QDir directory = QDir::current();
		const bool dirExists = directory.cd("./unlikely_existing");


		if (!dirExists)
		{
			if (!directory.mkdir("./unlikely_existing"))
			{
				qCritical("Directory could not be created");
				return 1;
			}
			else
			{
				qDebug().nospace().noquote() << "Folder " << directory.absolutePath() <<
					QDir::separator() << "unlikely_existing created successfully";
			}
		}

		directory.cd("./unlikely_existing");
		QFile file1(directory.absolutePath() + QDir::separator() + "first.txt");
		QFile file2(directory.absolutePath() + QDir::separator() + "second.txt");

		file1.open(QIODevice::WriteOnly);
		file2.open(QIODevice::WriteOnly);

		if (file1.isOpen() && file2.isOpen())
		{
			// Files can not be deleted if they are in use
			// so make sure to close it to make this snippet work
			file1.close();
			file2.close();

			qDebug() << "Files were created successfully on " << directory.absolutePath();
			qDebug() << "Now I am deleting them";
			QStringList entries = directory.entryList();
			foreach(QString entry, directory.entryList())
			{
				if (entry != "." && entry != "..")
					directory.remove(entry);
			}
		}
		else
		{
			qDebug() << "I could not create the files in " << directory.absolutePath();
		}
		return
			0;
	}
}
