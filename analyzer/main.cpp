#include <iostream>
#include <sstream>
#include <fstream>
#include "ever_main.h"
#include "watcher.h"
#include "log.h"
#include "conf.h"


int main(int argc, char *argv[])
{
    //  Init log
    Logger::instance()->init(&std::cout, Level::DEBUG);

    // Init config
    std::ifstream input("../conf/conf.json");
    std::stringstream sstr;
    while (input >> sstr.rdbuf());
    Conf::instance()->ConfRead(sstr.str().c_str());

    Watcher *watcher = Watcher::instance();

    // Init main process
    EverflowMain eMain;

    // Init connect and read config
    watcher->init(Conf::instance(), &eMain);
    watcher->init_connect();
    watcher->send_init();

    watcher->run();

    // eMain.run();
    // eMain.join();

    watcher->join();

    return 0;
}
