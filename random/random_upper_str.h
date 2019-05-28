#pragma once
#include <QDebug>

namespace RandomStringUppercase
{
	QString randString(int stringLength)
	{
		QString str;
		str.resize(stringLength);
		for (int s = 0; s < stringLength; ++s)
			str[s] = QChar('A' + char(qrand() % ('Z' - 'A')));

		return str;
	}

	void main()
	{
		for (int i = 0; i < 30; i++)
			qDebug() << randString(40);
	}
}
