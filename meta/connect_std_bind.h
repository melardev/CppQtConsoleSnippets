#pragma once
#include <QCoreApplication>
#include <QObject>
#include <functional>
#include <QDebug>

// Really powerful feature available since Qt5 we can use bind while connect() ing a signal to a slot
// std::bind has a lot of advantages, the one I am gonna show you right now is to save a value associated, 
// each time the slot is triggered we will receive that value, I find it useful for example when your have a chat app
// that app may open the same window but for different users you are chatting with, how to know which window is used
// with which user? obviously you can do it with plain C++ code with getters/setters and fields, but an express way
// is to use std::bind .... demo time !!
namespace ConnectStdBind
{
	class CameraWindow : public QObject
	{
	Q_OBJECT
	public:
		CameraWindow() = default;
		~CameraWindow() = default;
	signals:
		void windowClosed();
	};


	class ChatApp : public QObject
	{
	Q_OBJECT
	public:
		CameraWindow camuser1;
		CameraWindow camuser2;

		ChatApp()
		{
			// Notice the use of std::bind
			connect(&camuser1, &CameraWindow::windowClosed,
			        std::bind(&ChatApp::onWindowClosed, this, 1 /* User Id 1 */));

			connect(&camuser2, &CameraWindow::windowClosed,
			        std::bind(&ChatApp::onWindowClosed, this, 2/* User Id 2 */));
		}

		~ChatApp() = default;

		void simulateUsersDisconnected()
		{
			// emit camuser1.windowClosed();
			emit camuser2.windowClosed();
		}

	public slots:
		void onWindowClosed(qint32 userId)
		{
			qDebug() << QString("You can no loger chat with user with %1 because he disconnected").arg(userId);
		}
	};

	inline void main()
	{
		int argc = 0;
		QCoreApplication app(argc, Q_NULLPTR);
		// you are the user, you are streaming with two users
		ChatApp chatApp;
		chatApp.simulateUsersDisconnected();
		app.exec();
	}
}
