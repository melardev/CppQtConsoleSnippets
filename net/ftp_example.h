#pragma once
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>

namespace FtpExample
{
	static void main()
	{
		int argc = 0;
		QCoreApplication app(argc, Q_NULLPTR);
		QUrl ftpPath;
		ftpPath.setUrl("ftp://speedtest.tele2.net/1KB.zip");
		ftpPath.setUserName("root");
		ftpPath.setPassword("");
		ftpPath.setPort(21);

		QNetworkRequest request;
		request.setUrl(ftpPath);

		QScopedPointer<QNetworkAccessManager> manager(new QNetworkAccessManager);

		QNetworkReply* fetchFromFtpServer = manager->get(request);

		QEventLoop looper;
		QObject::connect(fetchFromFtpServer, &QNetworkReply::finished, [&]()
		{
			if (fetchFromFtpServer->error() != QNetworkReply::NoError)
			{
				qDebug() << "Error: " + fetchFromFtpServer->errorString();
			}
			else
			{
				QByteArray responseData;
				if (fetchFromFtpServer->isReadable())
				{
					responseData = fetchFromFtpServer->readAll();
				}

				QString dataString = QString(responseData);
				// Do something with the data, you have now the binary data, and the string data
			}
			looper.quit();
		});

		QObject::connect(fetchFromFtpServer,
		                 QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
		                 [&](QNetworkReply::NetworkError err)
		                 {
			                 qDebug() << "Error: " + fetchFromFtpServer->errorString();
			                 looper.exit();
		                 });

		looper.exec();
	}
}
