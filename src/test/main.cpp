#include <iostream>
#include "common.h"
#include "myLog.h"


using namespace std;

int main(int argc,char** argv)//(int argc,char* argv[])
{
    Common common;
    string log_path = common.get_log_path();
    MyLog *myLog = new MyLog(log_path,"MAIN");

    LOG(INFO)<<"MAIN Log Hello World!!!";

    delete myLog;

    return 0;
}