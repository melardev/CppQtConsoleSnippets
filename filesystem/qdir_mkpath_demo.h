#pragma once
#include <QString>
#include <QDirIterator>
#include <qstandardpaths.h>


QString const kPortableModeBeaconFileName = "Portable.bin"; ///< The name of the 'beacon' file used to detect if the application should run in portable mode
QString const kPortableAppsModeBeaconFileName = "PortableApps.bin"; ///< The name of the 'beacon file used to detect if the app is in PortableApps mode

//**********************************************************************************************************************
/// \brief Test if the application is running in portable mode
/// 
/// \return true if and only if the application is running in portable mode
//**********************************************************************************************************************
bool isInPortableModeInternal()
{
	QDir const appDir(QCoreApplication::applicationDirPath());
	return QFileInfo(appDir.absoluteFilePath(kPortableModeBeaconFileName)).exists() ||
		QFileInfo(appDir.absoluteFilePath(kPortableAppsModeBeaconFileName)).exists();
}

//**********************************************************************************************************************
/// \return true if and only if the application is in portable mode
//**********************************************************************************************************************
bool isInPortableMode()
{
	// portable mode state cannot change during the execution of an instance of the application, so we 'cache' the
	// value using a static variable
	static bool result = isInPortableModeInternal();
	return result;
}

bool usePortableAppsFolderLayout()
{
	return QFileInfo(QDir(QCoreApplication::applicationDirPath())
		.absoluteFilePath(kPortableAppsModeBeaconFileName)).exists();
}

//**********************************************************************************************************************
/// \return The absolute path of the folder where the user data is stored when the that is used when the application is 
/// in portable mode
//**********************************************************************************************************************
QString portableModeDataFolderPath()
{
	QDir const appDir(QCoreApplication::applicationDirPath());
	return usePortableAppsFolderLayout() ? appDir.absoluteFilePath("../../Data/settings")
		: appDir.absoluteFilePath("Data");
}


QString appDataDir()
{
	return isInPortableMode() ? portableModeDataFolderPath() :
		QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
}

void ensureAppDataDirExists()
{
	QString const path = appDataDir();
	QDir dir(path);
	if (dir.exists())
		return;
	QDir().mkpath(path);
	if (!dir.exists())
		throw Exception(QString("The application data folder '%1' could not be created")
			.arg(QDir::toNativeSeparators(path)));
}