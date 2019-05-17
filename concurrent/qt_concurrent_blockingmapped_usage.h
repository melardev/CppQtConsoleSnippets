#pragma once
#include <QtConcurrentMap>
#include <QVector>
#include <iostream>

namespace QtConcurrentBlockingMappedUsage
{
	int processIntegers(const int& i)
	{
		// it RETURNS integers which will be collected into the result
		return i + 1;
	}

	int main()
	{
		QVector<int> originalVector;
		originalVector.push_back(1);
		originalVector.push_back(2);
		originalVector.push_back(3);
		originalVector.push_back(4);

		for (auto i = 0; i < originalVector.size(); i++)
			std::cout << originalVector.at(i) << ", ";
		std::cout << std::endl << std::endl;


		// As the name states, it is blocking, it blocks until finished
		QVector<int> processedVector
			= QtConcurrent::blockingMapped<QVector<int>>(originalVector, processIntegers);

		std::cout << "Finished" << std::endl;
		for (int elem : processedVector)
			std::cout << elem << ", ";
		std::cout << std::endl << std::endl;


		return 0;
	}
}
