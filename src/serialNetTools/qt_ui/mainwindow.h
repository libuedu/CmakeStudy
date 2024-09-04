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
    // ��ť�ķ���
    void slot_btn_mySerial_send();
    // ��ť�Ŀ���
    void slot_btn_mySerial_open();
    // ����ģ���Ƿ�򿪳ɹ�
    void slot_module_status(const QVariantMap &);

signals:
    // UI ���ʹ�������
    void signal_serialSend(const QString &);
    // ����
    void signal_switch(const QVariantMap &);

private:
    Ui::MainWindow *ui_;
    QString addTimeStr(const QString &msg);
};
#endif // MAINWINDOW_H
