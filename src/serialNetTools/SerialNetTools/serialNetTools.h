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
    Q_OBJECT; // �������QtԪ����ϵͳ�ı��貿�֣����������źš��ۺ����Ե�����
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
