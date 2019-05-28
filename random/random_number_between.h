#pragma once
#include <QtGlobal>

namespace RandomNumberFrom0UpToN
{
	void main()
	{
		int number = 5;

		// qrand() returns a number between 0 and RAND_MAX(stdlib.h)
		// Number generate will be between 0(included) and 5(excluded)
		int randomValueUpto5 = qrand() % number;

		qDebug() << randomValueUpto5;

		for (int i = 0; i < 20; i++)
			qDebug() << (qrand() % number);
	}
}
