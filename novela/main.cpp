#include "view/viewMainWindow.h"

#include "singleton/singletonlog.h"
#include "controller/controllermain.h"


int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);

    ControllerMain a(argc, argv);
    int i_ret = a.exec();
    delete SingletonLog::getInstance();
    return i_ret;
}
