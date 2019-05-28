#pragma once
#include <QRandomGenerator>
#include <QDebug>

namespace GenerateRandomNumberBounded
{
	void main()
	{
		const quint32 randomNumber = QRandomGenerator::global()->bounded(50, 150);
		qDebug() << "Generated number " << randomNumber;
		qDebug() << "Generating numbers between 50 and 150";
		for (int i = 0; i < 10; i++)
			qDebug() << QRandomGenerator::global()->bounded(50, 150);
	}
}
