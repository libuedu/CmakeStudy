#pragma once

#include <iostream>
#include "mainwindow.h"
#include <QThread>
#include <QVariantMap>
#include <QHash>
#include "mySerial.h"
#include <QApplication>

using namespace std;

class SerialNetTools : public QObject
{
    Q_OBJECT; // 这个宏是Qt元对象系统的必需部分，它启用了信号、槽和属性等特性
public:
    SerialNetTools(int argc, char **argv);
    ~SerialNetTools();

    int init();

private:
    void switch_mySerial(const QVariantMap &);

public slots:
    void slot_switch(const QVariantMap &);

private:
    int argc_;
    char **argv_;
    QHash<QString, std::function<void(const QVariantMap &)>> switchMap_;
    MySerial *mySerial_ = nullptr;
    MainWindow *mainWindow_ = nullptr;
    QApplication *app_ = nullptr;
    QThread *mySerial_thread_ = nullptr;
};
