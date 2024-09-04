#include <iostream>
#include "serialNetTools.h"
#include "common.h"
#include "myLog.h"

int main(int argc, char **argv)
{
    Common common;
    std::string log_path = common.get_log_path();
    MyLog *myLog = new MyLog(log_path, "serialNetTools");
    SerialNetTools mySerialNetTools(argc, argv);
    LOG(INFO) << "serialNetTools start.";
    int res = mySerialNetTools.init();
    delete myLog;
    std::cout << "delete myLog" << std::endl;
    return res;
}