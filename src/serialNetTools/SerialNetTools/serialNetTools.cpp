#include "serialNetTools.h"
/**
 * 构造函数
 */
SerialNetTools::SerialNetTools(int argc, char **argv) : argc_(argc), argv_(argv)
{
}

/**
 * 析构函数
 */
SerialNetTools::~SerialNetTools()
{
}

/**
 * 初始化
 */
int SerialNetTools::init()
{
    app_ = new QApplication(argc_, argv_);
    mainWindow_ = new MainWindow(argc_, argv_);
    mainWindow_->show();

    /**
     * myserial 初始化
     */
    QObject::connect(mainWindow_, &MainWindow::signal_switch, this, &SerialNetTools::slot_switch);
    switchMap_["mySerial"] = [this](const QVariantMap &msg)
    { switch_mySerial(msg); };
    mySerial_ = new MySerial();
    mySerial_thread_ = new QThread();
    mySerial_->moveToThread(mySerial_thread_);

    QObject::connect(mySerial_, &MySerial::signal_openStatus, mainWindow_, &MainWindow::slot_module_status, Qt::QueuedConnection);
    QObject::connect(mySerial_, &MySerial::signal_serial, mainWindow_, &MainWindow::slot_send_textEdit, Qt::QueuedConnection);
    QObject::connect(mainWindow_, &MainWindow::signal_serialSend, mySerial_, &MySerial::slot_write, Qt::QueuedConnection);
    mySerial_thread_->start();

    return app_->exec();
}

void SerialNetTools::switch_mySerial(const QVariantMap &msg)
{
    bool state = msg.value("switch").toBool();
    if (state == true)
    {
        string serialName = msg.value("serialName").toString().toStdString();
        int baudRate = msg.value("baudRate").toInt();
        int checkData = msg.value("checkData").toInt();
        int dataBit = msg.value("dataBit").toInt();
        int stopBit = msg.value("stopBit").toInt();
        mySerial_->init("1", serialName, baudRate, checkData, dataBit, stopBit);

        QMetaObject::invokeMethod(mySerial_, "start", Qt::QueuedConnection);
    }
    else
    {
        LOG(INFO) << "mySerial_->stop()";
        QMetaObject::invokeMethod(mySerial_, "stop", Qt::QueuedConnection);
    }
}

/**
 * 各个模块的开关
 */
void SerialNetTools::slot_switch(const QVariantMap &msg)
{
    if (!msg.contains("type"))
    {
        return;
    }

    if (!msg.contains("switch"))
    {
        return;
    }

    QString type = msg.value("type").toString();
    switchMap_[type](msg);
}
