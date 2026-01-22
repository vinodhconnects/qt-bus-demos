#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QTextStream>
#include <QApplication>
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Normal I/O (Blocks UI)");

    QVBoxLayout layout(&window);

    QLabel label("Timer: 0");
    QPushButton button("Read stdin (BLOCKING)");

    layout.addWidget(&label);
    layout.addWidget(&button);

    int counter = 0;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&](){
        label.setText("Timer: " + QString::number(++counter));
    });
    timer.start(1000);

    QObject::connect(&button, &QPushButton::clicked, [&](){
        QTextStream ts(stdin);
        ts.readLine();   // ❌ BLOCKS EVENT LOOP
    });

    window.show();
    return app.exec();
}
*/
