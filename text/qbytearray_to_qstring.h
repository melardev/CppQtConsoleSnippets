#pragma once
#include <QString>
#include <QDebug>
#include <QTextCodec>

namespace QByteArrayToQString
{
	void main()
	{
		QByteArray byteArray;
		byteArray.append("Qt Console snippets");
		byteArray.append("A funny way to learn");

		byteArray.append('\t');

		byteArray.append('Q');
		byteArray.append('t');

		byteArray.append('\t');

		byteArray.append(2, 'Q');
		byteArray.append(2, 't');

		qDebug() << "::fromStdString(.toStdString)" << QString::fromStdString(byteArray.toStdString());
		qDebug() << "QString(byteArray)" << QString(byteArray);

		// The codes are available at https://www.iana.org/assignments/character-sets/character-sets.xml
		// The codec Qt will use will only work if it is installed on the system obviously
		// I have also snippets showing the value for UTF-8 and UTF-16 at qtextcodec_name_mib_pair
		const int UTF_8 = 106;
		const int UTF_16 = 1015;

		QTextCodec* utf8Codec = QTextCodec::codecForMib(UTF_8);
		qDebug() << "QTextCodec UTF-8" << utf8Codec->toUnicode(byteArray);
		// One liner:
		qDebug() << "QTextCodec UTF-16" << QTextCodec::codecForMib(UTF_16)->toUnicode(byteArray);

		qDebug() << "QTextCodec UTF-8" << QTextCodec::codecForName("UTF-8")->toUnicode(byteArray);
	}
}
