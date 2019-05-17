#pragma once
#include <QDebug>
#include <QOperatingSystemVersion>
#include <QSysInfo>
#include <QHostInfo>

namespace GetSystemBasicInfo
{
	int main()
	{
		qDebug().noquote().nospace() 
		<< "Hostname: " << QSysInfo::machineHostName() << "\n"
		<< "Windows Version: " << QSysInfo::windowsVersion() << "\n"
		<< "Current Type: " << QOperatingSystemVersion::currentType() << "\n"
		<< "Product Type: " << QSysInfo::productType() << "\n"
		<< "Product Version: " << QSysInfo::productVersion() << "\n"
		<< "Pretty Product Name: " << QSysInfo::prettyProductName() << "\n"
		<< "Local Hostname: " << QHostInfo::localHostName();

		return 0;
	}
}
