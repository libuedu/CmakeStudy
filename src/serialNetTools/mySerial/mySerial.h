#pragma once

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QVariantMap>
#include "myLog.h"
#include <QDebug>

using namespace std;

class MySerial : public QObject
{
    Q_OBJECT;

public:
    MySerial(const string &groupID, const string &serialName, const int &baudRate,
             const int &checkDate, const int &dataBit, const int &stopBit);
    ~MySerial();

public:
    bool start();
    void stop();

public slots:
    void slot_read();
    void slot_write(const QString &msg);
    void slot_start();

signals:
    void signal_serial(const QVariantMap &msg);

private:
    string groupID_;
    string serialName_ = "COM1";
    int baudRate_ = 115200;
    int checkDate_ = 0;
    int dataBit_ = 8;
    int stopBit_ = 1;

    QSerialPort *serialPort_ = nullptr;
};