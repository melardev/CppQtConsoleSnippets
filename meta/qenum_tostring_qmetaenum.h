#pragma once
#include <QMetaEnum>
#include <QDebug>

namespace QEnumToStringUsingQMetaEnum
{
	void main()
	{
		const QMetaEnum metaEnum = QMetaEnum::fromType<Qt::ConnectionType>();
		qDebug() << metaEnum.valueToKey(Qt::DirectConnection);
	}
}
