#pragma once
#pragma once

#include <QDate>
#include <QDebug>

namespace GetFormattedDateString
{
	int main()
	{
		// This snippet is really useful when you wanna generate a file name once per day
		// remember this is QDate and not QDateTime, if you want hours, minutes, seconds
		// look QDateTime snippet
		QDate today = QDate::currentDate();

		const QString formattedDateString = today.toString("'data_'MM_dd_yyyy'.txt'");
		qDebug() << "Custom format " << formattedDateString;
		return 0;
	}
}
