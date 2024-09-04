#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(int argc, char **argv, QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    // 串口
    QObject::connect(ui_->pushButton_serial_open, &QPushButton::clicked, this, &MainWindow::slot_btn_mySerial_open);
    QObject::connect(ui_->pushButton_serial_send, &QPushButton::clicked, this, &MainWindow::slot_btn_mySerial_send);

    // 获取串口列表
    QList<QSerialPortInfo> serialNames = QSerialPortInfo::availablePorts();
    foreach (const QSerialPortInfo &info, serialNames)
    {
        ui_->comboBox_serialName->addItem("/dev/" + info.portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui_;
}

/**
 * UI 汇总显示 接收
 */
void MainWindow::slot_send_textEdit(const QVariantMap &msg)
{
    if (!msg.contains("type"))
    {
        return;
    }

    if (!msg.contains("data"))
    {
        return;
    }
    QString type = msg.value("type").toString();
    QString str = addTimeStr(type);
    str += msg.value("data").toString();
    ui_->textEdit_sub->append(str);
}

/*
    时间信息打印
*/
QString MainWindow::addTimeStr(const QString &msg)
{
    QDateTime now = QDateTime::currentDateTime();
    QString str = now.toString("hh:mm:ss.zzzzzz");
    str += (" " + msg + ": ");
    return str;
}

/*
    串口发送按钮
*/
void MainWindow::slot_btn_mySerial_send()
{
    QString send_msg = ui_->lineEdit_serial_input->text();
    emit signal_serialSend(send_msg);

    QString str = addTimeStr("mySerial");
    str += send_msg;
    ui_->textEdit_send->append(str);
}

/*
    串口的开关按钮
*/
void MainWindow::slot_btn_mySerial_open()
{
    QString serialName = ui_->comboBox_serialName->currentText();
    int baudRate = ui_->lineEdit_baudRate->text().toInt();
    QString check = ui_->comboBox_checkData->currentText();
    int dataBit = ui_->comboBox_dataBit->currentText().toInt();
    int stopBit = ui_->comboBox_stopBit->currentText().toInt();

    LOG(INFO) << "serialName is " << serialName.toStdString();
    LOG(INFO) << "baudRate is " << baudRate;
    LOG(INFO) << "check is " << check.toStdString();
    LOG(INFO) << "dataBit is " << dataBit;
    LOG(INFO) << "stopBit is " << dataBit;

    int check_num = 1;
    if (check == "NoParity")
    {
        check_num = 0;
    }
    else if (check == "EvenParity")
    {
        check_num = 2;
    }
    else if (check == "OddParity")
    {
        check_num = 3;
    }
    else if (check == "SpaceParity")
    {
        check_num = 4;
    }
    else if (check == "MarkParity")
    {
        check_num = 5;
    }
    else
    {
        check_num = -1;
    }

    QVariantMap data;
    data["type"] = "mySerial";
    data["serialName"] = serialName;
    data["baudRate"] = baudRate;
    data["checkData"] = check_num;
    data["dataBit"] = dataBit;
    data["stopBit"] = stopBit;

    if (ui_->pushButton_serial_open->text() == "打开")
    {
        data["switch"] = true;
        ui_->pushButton_serial_open->setText("关闭");
        ui_->pushButton_serial_open->setStyleSheet("background-color: green;");
        ui_->pushButton_serial_open->setEnabled(false);
    }
    else
    {
        data["switch"] = false;
        ui_->pushButton_serial_open->setText("打开");
        ui_->pushButton_serial_open->setStyleSheet("background-color: { }");
    }

    // ui_->pushButton_serial_open->setEnabled(false);
    emit signal_switch(data);

    // 获取串口列表
    QList<QSerialPortInfo> serialNames = QSerialPortInfo::availablePorts();
    foreach (const QSerialPortInfo &info, serialNames)
    {
        ui_->comboBox_serialName->addItem("/dev/" + info.portName());
    }
}

/*
    各个模块的状态返回
*/
void MainWindow::slot_module_status(const QVariantMap &msg)
{
    if (!msg.contains("type"))
    {
        return;
    }

    if (!msg.contains("state"))
    {
        return;
    }

    QString type = msg.value("type").toString();
    bool state = msg.value("state").toBool();

    if (type == "mySerial")
    {
        if (!state)
        {
            LOG(INFO) << "串口打开失败...";
            ui_->pushButton_serial_open->setText("打开");
            ui_->pushButton_serial_open->setStyleSheet("background-color: { }");

            QDateTime now = QDateTime::currentDateTime();
            QString str = addTimeStr("mySerial");
            str += "串口打开失败";
            ui_->textEdit_sub->append(str);
        }
        ui_->pushButton_serial_open->setEnabled(true);
    }
}