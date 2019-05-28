#pragma once
#include <QTextCodec>
#include <QDebug>

namespace QTextCodecWhatIsAvailable
{
	void main()
	{
		QList<int> mibs = QTextCodec::availableMibs();

		qDebug() << "Available mibs";
		Q_FOREACH(const int mib, mibs)
			qDebug() << mib;

		qDebug() << "\n\n";

		QList<QByteArray> codecs = QTextCodec::availableCodecs();
		qDebug() << "Available codecs";
		// foreach is also a Qt macro, it is the same as Q_FOREACH
		// I presented the Q_FOREACH snippet in core/q_foreach_macro.h

		foreach(const auto& codec, codecs)
			qDebug() << QString(codec);
	}
}
