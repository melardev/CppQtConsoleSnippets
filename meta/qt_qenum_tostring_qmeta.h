#pragma once
#include <QDebug>
#include <QMetaEnum>

namespace QEnumToStringQMeta
{
	template <typename QEnum>
	QString getQEnumValueString(const QEnum& value)
	{
		const char* enumName = Qt::qt_getEnumName(value);
		const QMetaObject* metaObject = Qt::qt_getEnumMetaObject(value);
		const int index = metaObject->indexOfEnumerator(enumName);
		const char* toString = metaObject->enumerator(index).valueToKey(value);
		return toString;
	}

	void main()
	{
		const QString toString = getQEnumValueString(Qt::DirectConnection);
		qDebug() << toString;
	}
}
