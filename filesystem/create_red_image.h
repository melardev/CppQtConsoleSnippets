#pragma once
#include <QImage>
#include <QDir>
#include <QDebug>

namespace CreateRedImage
{
	inline void main()
	{
		// 100px width, 100px height
		QImage image(100, 100, QImage::Format_ARGB32);
		const QColor color = QColor(255, 0, 0);
		image.fill(color);
		QDir directory = QDir::current();
		const QString filepath = directory.absoluteFilePath("red.png");
		if (image.save(filepath))
		{
			qDebug() << "File saved successfully";
			qDebug() << "You can find the image in " << directory.absolutePath();
		}
	}
}
