#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QSocketNotifier>
#include <QTextStream>

#include <unistd.h>   // STDIN_FILENO

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("FD-driven I/O (GUI Responsive)");

    QVBoxLayout layout(&window);

    QLabel timerLabel("Timer: 0");
    QLabel inputLabel("Type in terminal and press Enter");

    layout.addWidget(&timerLabel);
    layout.addWidget(&inputLabel);

    // Timer proves event loop is alive
    int counter = 0;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&](){
        timerLabel.setText("Timer: " + QString::number(++counter));
    });
    timer.start(1000);

    // FD-driven stdin watcher
    QSocketNotifier notifier(STDIN_FILENO, QSocketNotifier::Read);

    QObject::connect(&notifier, &QSocketNotifier::activated,
                     [&](int){
                         QTextStream ts(stdin);
                         QString line = ts.readLine();
                         inputLabel.setText("Input: " + line);
                     });

    window.show();
    return app.exec();
}
