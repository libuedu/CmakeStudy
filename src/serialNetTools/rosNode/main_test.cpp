#include <iostream>
#include "rosNode.h"
#include <QCoreApplication>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    RosNode *rosNode = new RosNode(argc, argv);
    rosNode->init();

    QThread *thread = new QThread();
    rosNode->moveToThread(thread);
    QObject::connect(rosNode, &RosNode::signal_rosShutdown, &app, &QCoreApplication::quit);
    QObject::connect(thread, &QThread::started, rosNode, &RosNode::run);

    // 启动线程
    thread->start();

    int result = app.exec();

    // 清理资源
    rosNode->deleteLater();
    thread->deleteLater();

    sleep(1);

    return 0;
}