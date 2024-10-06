//
// Created by Paul Walker on 10/6/24.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "libMTSClient.h"
int main(int argc, char **argv)
{
    auto cl = MTS_RegisterClient();

    double rt[128];
    for (auto i=0; i<128; ++i)
        rt[i] = 0;

    while(true)
    {
        bool print{false};
        for (int i=0; i<128; ++i)
        {
            auto rtv = MTS_RetuningInSemitones(cl, i, 0);
            if (rtv != rt[i])
                print = true;
            rt[i] = rtv;
        }
        if (print)
        {
            std::cout << "-------------" << std::endl;
            for (int i=60; i<60 + 24; i+4)
            {
                std::cout << i << " " ;
                for (int j=0; j<4; ++j)
                    std::cout << rt[i + j] << " ";
                std::cout << std::endl;
            }
        }
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
    MTS_DeregisterClient(cl);
    return 0;
}