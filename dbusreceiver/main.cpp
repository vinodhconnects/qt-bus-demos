#include <QCoreApplication>
#include <QDBusConnection>
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Receiver receiver;

    QDBusConnection::sessionBus().connect(
        QString(),                // any service
        "/org/pool/signals",
        "org.pool.signals",
        "Tick",                   // signal
        &receiver,
        SLOT(onTick(QString,int))
        );

    return app.exec();
}
