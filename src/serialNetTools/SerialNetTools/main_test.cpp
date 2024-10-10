#include <iostream>
#include "serialNetTools.h"

int main(int agrc,char** argv)
{
    SerialNetTools mySerialNetTools;
    int res = mySerialNetTools.myAdd(1,2);

    std::cout<<"Hello world! res: "<<res<<std::endl;
    return 0;
}