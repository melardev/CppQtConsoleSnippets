#pragma once
#include <QByteArray>
#include <QFile>
#include <QDebug>

namespace QByteArrayScanDemo
{
	int main()
	{
		QFile file("D:/temp/text_file.txt");
		file.open(QIODevice::ReadOnly); // Open for read only
		QByteArray buffer;
		if (file.isOpen())
		{
			buffer = file.readAll();
			qDebug() << "Sorry, Melardev word was not found on that file";
		}
		else
		{
			qDebug() << "Could not open the file, using QByteArray from QString then";
			buffer = QString("Melardev is a really cool guy").toUtf8();
		}

		for (const char *p = buffer.data(), *word = p, *end = p + buffer.length(); // starting point
		     p <= end; // condition
		     ++p) // step
		{
			switch (*p)
			{
			case ' ':
			case '\r':
			case '\n':
			case '\t':
			case '\0':
				if (word != p)
				{
					if (!strncmp(word, "Melardev", size_t(p - word)))
					{
						qDebug() << "Yes, the QByteArray begins with Melardev";
						return 0;
					}

					word = p + 1;
				}
			default: continue;
			}
		}

		return 0;
	}
}
