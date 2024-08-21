#include "mySerial.h"

/*
    ���캯��
*/
MySerial::MySerial(const string &groupID, const string &serialName, const int &baudRate,
                   const int &checkDate, const int &dataBit, const int &stopBit)
    : groupID_(groupID), serialName_(serialName), baudRate_(baudRate),
      checkDate_(checkDate), dataBit_(dataBit), stopBit_(stopBit)
{
}
/*
    ��������
*/
MySerial::~MySerial()
{
    if (serialPort_ != nullptr)
    {
        serialPort_->flush(); // ��ջ�����
        serialPort_->close();
        delete serialPort_;
        serialPort_ = nullptr;
    }
}

/*
    ��ȡ��������
*/
void MySerial::slot_read()
{
    if (serialPort_->bytesAvailable() > 0)
    {
        QByteArray serial_data;
        serial_data = serialPort_->readAll();

        LOG(INFO) << "serial_data: " << serial_data.toStdString();

        QVariantMap data;
        data["type"] = "mySerial";
        data["data"] = serial_data;
        emit signal_serial(data);
    }
}
/*
    ��������
*/
void MySerial::slot_start()
{
    start();
}
/*
    д�봮������
*/
void MySerial::slot_write(const QString &msg)
{
    if (serialPort_ != nullptr)
    {
        QByteArray data = msg.toUtf8();
        serialPort_->write(data);
    }
}
/*
    ���Դ򿪴���
*/
bool MySerial::start()
{
    if (serialPort_ != nullptr)
    {
        serialPort_->flush(); // ��ջ�����
        serialPort_->close();
        delete serialPort_;
        serialPort_ = nullptr;
    }

    serialPort_ = new QSerialPort();
    // 1.���ô�������
    serialPort_->setPortName(QString::fromStdString(serialName_));
    // 2.���ò�����
    serialPort_->setBaudRate(baudRate_);
    // 3.����У��λ
    switch (checkDate_)
    {
    case 0:
        serialPort_->setParity(QSerialPort::NoParity);
        break;
    case 2:
        serialPort_->setParity(QSerialPort::EvenParity);
        break;
    case 3:
        serialPort_->setParity(QSerialPort::OddParity);
        break;
    case 4:
        serialPort_->setParity(QSerialPort::SpaceParity);
        break;
    case 5:
        serialPort_->setParity(QSerialPort::MarkParity);
        break;
    case -1:
        serialPort_->setParity(QSerialPort::UnknownParity);
        break;
    default:
        break;
    }
    // 4.��������λ
    switch (dataBit_)
    {
    case 5:
        serialPort_->setDataBits(QSerialPort::Data5);
        break;
    case 6:
        serialPort_->setDataBits(QSerialPort::Data6);
        break;
    case 7:
        serialPort_->setDataBits(QSerialPort::Data7);
        break;
    case 8:
        serialPort_->setDataBits(QSerialPort::Data8);
        break;
    case -1:
        serialPort_->setDataBits(QSerialPort::UnknownDataBits);
        break;
    default:
        break;
    }
    // 5.����ֹͣλ
    switch (dataBit_)
    {
    case 1:
        serialPort_->setStopBits(QSerialPort::OneStop);
        break;
    case 2:
        serialPort_->setStopBits(QSerialPort::TwoStop);
        break;
    case 3:
        serialPort_->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    case -1:
        serialPort_->setStopBits(QSerialPort::UnknownStopBits);
        break;
    default:
        break;
    }
    // 6.���ÿ�����
    serialPort_->setFlowControl(QSerialPort::NoFlowControl);
    // 7.�򿪴���
    bool open_state = serialPort_->open(QIODevice::ReadWrite);
    if (open_state)
    {
        // ������ȡ�������ݵ�����
        QObject::connect(serialPort_, &QSerialPort::readyRead, this, &MySerial::slot_read);
        return true;
    }
    else
    {
        stop();
        return false;
    }
}
/*
    �رմ���
*/
void MySerial::stop()
{
    if (serialPort_ != nullptr)
    {
        serialPort_->flush(); // ��ջ�����
        serialPort_->close();
        delete serialPort_;
        serialPort_ = nullptr;
    }
}