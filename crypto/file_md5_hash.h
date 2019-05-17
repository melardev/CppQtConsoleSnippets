#pragma once
#include <QByteArray>
#include <QDebug>
#include <QCryptographicHash>
#include <QFile>


namespace Md5FromFile
{
	QByteArray getHashFromFilePath(const QString& fileName, QCryptographicHash::Algorithm hashAlgorithm)
	{
		QFile file(fileName);
		if (file.open(QFile::ReadOnly))
		{
			QCryptographicHash hash(hashAlgorithm);
			if (hash.addData(&file))
			{
				// closed the file
				file.close();
				return hash.result();
			}
			// closed the file
			file.close();
		}
		else
		{
			qDebug() << "Could not open the file";
		}
		return QByteArray();
	}

	void main()
	{
		// QCryptographicHash::Md5, QCryptographicHash::Sha1, etc.
		QByteArray md5Hash = getHashFromFilePath("D:/temp/text_file.txt",
		                                         QCryptographicHash::Md5);

		if (md5Hash.isEmpty() || md5Hash.isNull())
		{
			qDebug() << "Something went wrong";
		}

		qDebug().noquote() << QString(md5Hash.toHex());
	}
}
