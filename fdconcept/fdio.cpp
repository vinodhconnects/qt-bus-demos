#include <QCoreApplication>
#include <QTimer>
#include <QSocketNotifier>
#include <QTextStream>
#include <QDebug>

#include <unistd.h>   // ✅ REQUIRED for STDIN_FILENO

/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Timer to prove event loop is alive
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [](){
        qDebug() << "Timer tick (FD IO)";
    });
    timer.start(1000);

    qDebug() << "Type something and press Enter (FD IO)...";

    // FD-based stdin watcher
    QSocketNotifier notifier(STDIN_FILENO, QSocketNotifier::Read);

    QObject::connect(&notifier, &QSocketNotifier::activated,
                     [&](int){
                         QTextStream ts(stdin);
                         QString line = ts.readLine();
                         qDebug() << "You typed:" << line;
                     });

    return app.exec();
}

*/
