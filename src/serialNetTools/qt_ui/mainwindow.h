#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "myLog.h"
#include <QVariantMap>
#include <QDateTime>
#include <QSerialPortInfo>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char **argv, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slot_send_textEdit(const QVariantMap &);
    // 按钮的发送
    void slot_btn_mySerial_send();
    // 按钮的开关
    void slot_btn_mySerial_open();
    // 功能模块是否打开成功
    void slot_module_status(const QVariantMap &);

signals:
    // UI 发送串口数据
    void signal_serialSend(const QString &);
    // 开关
    void signal_switch(const QVariantMap &);

private:
    Ui::MainWindow *ui_;
    QString addTimeStr(const QString &msg);
};
#endif // MAINWINDOW_H
