#pragma once
#include <QDebug>

namespace StdOutMessageTypes
{
	void main()
	{
		qDebug() << "Debugging message";
		qDebug("Debugging Messages");
		qDebug("Formatted messages: %s;%d", "Melardev", 100);

		// qFatal("Fatal Error!!!"); // This triggers a crash

		qWarning("Warning message");
		qCritical("Critical message");
		qErrnoWarning(0, "qErrnoWarning message");
	}
}
