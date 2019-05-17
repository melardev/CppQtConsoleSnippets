#pragma once
#include <QDebug>
#include <QDirIterator>


namespace RemoveAllImagesDemo
{
	void main()
	{
		const QStringList extensions = QStringList() << "*.png" << "*.jpeg";

		QDirIterator dirIterator("./", extensions);
		while (dirIterator.hasNext())
		{
			QString imageFile = dirIterator.next();
			qDebug().noquote().nospace() << "Removing " + imageFile;
			try
			{
				QFile file(imageFile);

				qDebug().noquote().nospace() << "Deleting " << dirIterator.filePath();

				// or longer way
				// qDebug().noquote().nospace() << "Deleting " << dirIterator.path() << QDir::separator() << file.fileName();

				// Uncomment this line to perform the remove, I commented it just in case, accidents happen :)
				// file.remove();
			}
			catch (...)
			{
				qDebug() << "Error deleting " << imageFile;
			}
		}
	}
}
