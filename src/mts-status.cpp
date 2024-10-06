#include <iostream>
#include "libMTSMaster.h"

int main(int argc, char **argv)
{
    std::cout << "MTS Status" << std::endl;
    std::cout << "   IPC : " << MTS_HasIPC() << std::endl;
    std::cout << "   Can Register Master: " << MTS_CanRegisterMaster() << std::endl;
    std::cout << "   Client Count: " << MTS_GetNumClients() << std::endl;

    if (argc >= 2)
    {
        auto s = std::string(argv[1]);
        if (s == "--reset")
        {
            std::cout << "Resetting MTS-ESP" << std::endl;
            MTS_Reinitialize();
        }
        else
        {
            std::cout << "Unknown command line argument " << s << std::endl;
        }
    }
    else
    {
        std::cout
            << "Re-run with `--reset` as first arg to reset. "
            << std::endl;
    }
    return 0;
}
