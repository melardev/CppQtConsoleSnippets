#pragma once


#include <QByteArray>
#include <QDebug>
#include <QCryptographicHash>
#include <QFile>


namespace Md5FromString
{
	QByteArray getHashFromFilePath(const QString& fileName, QCryptographicHash::Algorithm hashAlgorithm)
	{
		QCryptographicHash hash(hashAlgorithm);

		QByteArray contents;
		QFile file(fileName);
		if (file.open(QFile::ReadOnly))
		{
			contents = file.readAll();

			// closed the file
			file.close();
		}
		else
		{
			QString randomStr = "Please hash me";
			qDebug() << "Could not open the file, using " << randomStr;
			contents = randomStr.toUtf8();
		}

		hash.addData(contents);
		return hash.result();
	}

	void main()
	{
		// QCryptographicHash::Md5, QCryptographicHash::Sha1, etc.
		QByteArray hashResult = getHashFromFilePath("D:/temp/text_file.txt",
		                                            QCryptographicHash::Md5);

		if (hashResult.isEmpty() || hashResult.isNull())
		{
			qDebug() << "Something went wrong";
		}

		qDebug().noquote() << QString(hashResult.toHex());
	}
}
