#include "mySerial.h"
#include <iostream>
#include "myLog.h"
#include "common.h"
#include <QCoreApplication>

int main(int argc, char **argv)
{
    Common common;
    std::string log_path = common.get_log_path();
    MyLog *myLog = new MyLog(log_path, "mySerial");

    LOG(INFO) << "mySerial test start.";

    QCoreApplication app(argc, argv);

    MySerial *mySerial = new MySerial("1", "/dev/ttySO", 115200, 0, 8, 1);
    QMetaObject::invokeMethod(mySerial, "slot_start", Qt::QueuedConnection);

    return app.exec();
}