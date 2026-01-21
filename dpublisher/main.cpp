#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int i=1;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&](){
        QDBusMessage msg =
            QDBusMessage::createSignal(
                "/org/pool/signals",
                "org.pool.signals",
                "Tick");

        msg << QString("Hello from D-Bus ") << i;
        QDBusConnection::sessionBus().send(msg);
        i++;
        qDebug() << "Signal sent";
    });

    timer.start(1000);
    return app.exec();
}
