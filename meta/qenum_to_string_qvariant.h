#pragma once
#include <QVariant>

namespace QEnumToStringUsingQVariant
{
	void main()
	{
		// const QString value = QVariant::fromValue(Qt::DirectConnection).toString();
		// Or:
		const QString value = QVariant::fromValue(Qt::DirectConnection).value<QString>();
		qDebug() << value;
	}
}
