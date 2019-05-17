#pragma once

#include <QVector>
#include <QRandomGenerator>

namespace QVectorUsage
{
	int main()
	{
		QVector<int> vectorOfNumbers;
		vectorOfNumbers.reserve(6);
		vectorOfNumbers.append(0);
		vectorOfNumbers.append(1);
		vectorOfNumbers.append(2);
		vectorOfNumbers.append(3);
		vectorOfNumbers.append(4);
		vectorOfNumbers.append(5);

		// Yeah QVector can also reallocate memory to hold more elements thant first thought
		vectorOfNumbers.append(6);

		vectorOfNumbers.append(QRandomGenerator::global()->bounded(0, 5));
		vectorOfNumbers.append(QRandomGenerator::global()->bounded(6, 10));
		vectorOfNumbers.append(QRandomGenerator::global()->bounded(11, 15));

		QVector<int>::const_iterator vecIterator = vectorOfNumbers.cbegin();
		while (vecIterator != vectorOfNumbers.constEnd())
		{
			std::cout << *vecIterator << ", ";
			vecIterator++;
		}

		std::cout << std::endl;
		return 0;
	}
}
