#include "mySerial.h"
#include <iostream>
#include "myLog.h"
#include "common.h"
#include <QCoreApplication>
#include <QThread>

int main(int argc, char **argv)
{
    Common common;
    std::string log_path = common.get_log_path();
    MyLog *myLog = new MyLog(log_path, "mySerial");

    LOG(INFO) << "mySerial test start.";

    QCoreApplication app(argc, argv);
    MySerial *mySerial = new MySerial();

    QThread *thread = new QThread();
    mySerial->moveToThread(thread);

    thread->start();
    LOG(INFO) << "mySerial start.";

    mySerial->init("1", "/dev/ttyS1", 115200, 0, 8, 1);
    QMetaObject::invokeMethod(mySerial, "start", Qt::QueuedConnection);

    // QThread *thread = new QThread();
    // mySerial->moveToThread(thread);
    // QObject::connect(thread, &QThread::started, mySerial, &MySerial::slot_start);
    // thread->start();
    int result = app.exec();
    // mySerial->deleteLater();
    // thread->deleteLater();

    return result;
}