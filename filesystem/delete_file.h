#pragma once
#include <QFile>
#include <QDirIterator>
#include <QDebug>

namespace DeleteFile
{
	int main()
	{
		// Run the create_red_image.h snippet before
		// that snippet will create red.png
		const QString currentFilePath = QDir::current().absolutePath();
		const QString redImageFilePath = currentFilePath + QDir::separator() + "red.png";

		const QString filePath(redImageFilePath);
		QFile file(filePath);
		if (file.exists())
		{
			file.remove();
			qDebug("File deleted successfully");

			// You can also run the remove method statically
			// you should do that only if don't care if the file exists or not
			// QFile::remove(currentFilePath);
		}
		else
		{
			qDebug("Could not open the file, have you run the create_red_image.h snippet?");
		}

		return 0;
	}
}
