#include <QCoreApplication>
#include <QTimer>
#include <QTextStream>
#include <QDebug>
/*
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Timer to prove event loop activity
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [](){
        qDebug() << "Timer tick (NORMAL IO)";
    });
    timer.start(1000);

    qDebug() << "Type something and press Enter (NORMAL IO)...";

    // ❌ BLOCKING CALL
    QTextStream ts(stdin);
    QString line = ts.readLine();   // Event loop BLOCKS here

    qDebug() << "You typed:" << line;

    return app.exec();
}*/
