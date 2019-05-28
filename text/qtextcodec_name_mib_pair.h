#pragma once
#include <QTextCodec>
#include <QDebug>

namespace QTextCodecNameMibPair
{
	void main()
	{
		QList<QByteArray> availableCodecNames = QTextCodec::availableCodecs();
		qDebug() << "Available codecs";
		// foreach is also a Qt macro, it is the same as Q_FOREACH
		// I presented the Q_FOREACH snippet in core/q_foreach_macro.h

		// C++11 loop syntax
		for (const auto& codecName : availableCodecNames)
		{
			QTextCodec* textCodec = QTextCodec::codecForName(codecName);
			qDebug().noquote() << QString("%1: %2").arg(QString(textCodec->name())).arg(textCodec->mibEnum());
		}
	}
}
