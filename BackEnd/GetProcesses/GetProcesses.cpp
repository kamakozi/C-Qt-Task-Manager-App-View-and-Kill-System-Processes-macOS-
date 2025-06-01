#include <sys/sysctl.h>
#include "GetProcesses.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "../Processes/Proceses.hpp"
#include <memory>

#include "../TaskManager.h"

std::vector<std::unique_ptr<Proceses>> GetProcesses::get_process() {
    std::ofstream writeFile("Logs.txt");

    int mib[4] = {CTL_KERN, KERN_PROC,KERN_PROC_ALL,0};


    size_t bufferSize = 0;
    if (sysctl(mib,4,nullptr,&bufferSize,nullptr,0) == -1) {
        perror("Sysctl failed to get buffer size!");
        writeFile << "Sysctl failed to get buffer size!" << std::endl;
        writeFile.close();
        return {};
    }

    std::vector<char> buffer(bufferSize);

    if (sysctl(mib,4,buffer.data(),&bufferSize,nullptr,0)== -1) {
        perror("Sysctl fail to get buffer data");
        writeFile << "Sysctl failed to get buffer data!" << std::endl;
        writeFile.close();
        return {};
    }

    kinfo_proc* processList = reinterpret_cast<kinfo_proc *>(buffer.data());
    int count = bufferSize / sizeof(kinfo_proc);


    std::vector<std::unique_ptr<Proceses>>all_processes;
    for (int i = 0;i < count;i++) {

        int pId = processList[i].kp_proc.p_pid;
        std::string taskName = processList[i].kp_proc.p_comm;

        all_processes.push_back(std::make_unique<Proceses>(pId,taskName));

    }

    return all_processes;
}





