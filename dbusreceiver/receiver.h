#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QDebug>

class Receiver : public QObject
{
    Q_OBJECT

public:
    explicit Receiver(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    void onTick(const QString &msg, int messageno) {
        qDebug() << "Received:" << msg << "::" <<messageno;
    }
};

#endif // RECEIVER_H
