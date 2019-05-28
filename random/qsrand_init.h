#pragma once
#include <QDate>
#include <ctime>
#include <QDebug>

namespace QsRandInitialization
{
	void main()
	{
		// Different ways of initializing qsrand

		qsrand(QDateTime::currentMSecsSinceEpoch());
		// Or, the below is very strange to me, but I saw it some times, I prefer the above
		// qsrand(std::time(Q_NULLPTR));

		int value = qrand();
		qDebug() << "value: " << value;
		qDebug() << qrand();
		qDebug() << qrand();
		qDebug() << qrand();

		for (int i = 0; i < 20; i++)
			qDebug() << qrand();
	}
}
