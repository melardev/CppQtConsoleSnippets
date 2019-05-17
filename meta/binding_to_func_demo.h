#pragma once
#include <QCoreApplication>
#include <QDebug>

// Available only from Qt 5
// This demo shows how to bind a signal to a function that is not a member function of a QObject derived class
namespace BindingToFuncNonQObject
{
	void standaloneFunc()
	{
		qDebug() << "I am not a QObject, but this slot should be Called";
	}

	int main()
	{
		int argc = 0;

		QCoreApplication app(argc, nullptr);

		QObject::connect(&app, &QCoreApplication::organizationNameChanged, standaloneFunc);
		QCoreApplication::setOrganizationName("Melardev co");

		return 0;
	}
}
