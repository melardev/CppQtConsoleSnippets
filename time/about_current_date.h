#pragma once

#include <QDate>
#include <QDebug>

namespace AboutCurrentDate
{
	int main()
	{
		QDate today = QDate::currentDate();
		qDebug() << "Month " << today.month();
		qDebug() << "Day" << today.day();
		qDebug() << "Day of the week " << today.dayOfWeek();
		qDebug() << "Day of the year " << today.dayOfYear();
		qDebug() << "Days in year " << today.daysInYear();
		qDebug() << "Year " << today.year();
		qDebug() << "Is leap year " << today.isLeapYear(today.year());
		qDebug() << "Is valid " << today.isValid();
		return 0;
	}
}
