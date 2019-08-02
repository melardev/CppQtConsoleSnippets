#pragma once
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QDebug>

#ifdef Q_OS_WIN
#include "Windows.h"
#endif

namespace DetachedProcess
{
	class DetachableProcess : public QProcess
	{
	public:
		DetachableProcess(QObject* parent = 0)
			: QProcess(parent)
		{
		}

		void detach()
		{
			waitForStarted();
			setProcessState(QProcess::NotRunning);
		}
	};


	static int main()
	{
#ifndef Q_OS_WIN
		qDebug() << "This snippet is only implemented for Windows, if you know how to add support "
			"for linux and/or mac please make a pull request";
		return 1;
#endif
		DetachableProcess process;
		const QString program = "cmd.exe";

		process.setCreateProcessArgumentsModifier(
			[](QProcess::CreateProcessArguments* args)
			{
#ifdef Q_OS_WIN
				// args->flags |= CREATE_NEW_CONSOLE; // Open the process in a whole new terminal window?
				// This flag is used to enable redirection
				args->startupInfo->dwFlags &= ~STARTF_USESTDHANDLES;
#endif
			});

		process.start(program);
		process.detach();

		qDebug() << "Sleeping for 10 sec";
		QThread::currentThread()->sleep(2);
		qDebug() << "Exiting Qt App, don't worry the console is still alive, remember it is detached ;)";
		return 0;
	}
}
