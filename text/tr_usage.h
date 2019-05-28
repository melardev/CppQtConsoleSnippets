#pragma once
#include <QString>
#include <QDebug>

namespace TrUsage
{
	void main()
	{
		QString pattern = QObject::tr("<font color='%1'>%2</font>");
		// One arg at a time using fluent API
		qDebug() << pattern.arg("blue").arg("Beatiful colors");

		// many items at once, be warned, even though there are many overloads that take many arguments
		// not all of them treat the rest of arguments to replace the placeholders
		// for example in the arg(int, int); The first int replaces a placeholder, but the other is the Field width.
		// and not a value to replace the second placeholder
		qDebug() << QObject::tr("%1 %2").arg("Melar", "Dev");
	}
}
