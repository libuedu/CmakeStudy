#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(int argc,char** argv, QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , rosNode_(argc,argv)
{
    ui_->setupUi(this);
    rosNode_.init();
    QObject::connect(ui_->pushButton_send,&QPushButton::clicked,this,&MainWindow::slot_btn_send);
    QObject::connect(this,&MainWindow::signal_send,this,&MainWindow::slot_send_textEdit);

    QObject::connect(this,&MainWindow::signal_rosPub,&rosNode_,&RosNode::slot_pubStrMsg);
    QObject::connect(&rosNode_,&RosNode::signal_strMsg,this,&MainWindow::slot_send_textEdit);

    std::string log_path = common_log_.get_log_path();
    myLog_ = new MyLog(log_path, "mainWindow");

    LOG(INFO)<<"mainWindow Log Hello World!!!";

}

MainWindow::~MainWindow()
{
    delete ui_;
    delete myLog_;
}


/**
 * 发送按钮的槽函数
 */
void MainWindow::slot_btn_send()
{
    QString send_msg = ui_->lineEdit_input->text();
    qDebug()<<send_msg;
    // emit signal_send(send_msg);
    emit signal_rosPub(send_msg);
}

/**
 * 槽函数
 */
void MainWindow::slot_send_textEdit(const QString& msg)
{
    ui_->textEdit_sub->append(msg);
}