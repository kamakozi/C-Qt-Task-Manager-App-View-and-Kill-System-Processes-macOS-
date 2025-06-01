//
// Created by ziga zoric on 01.06.25.
//

#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <vector>
#include <string>
#include <unordered_map>

#include "Processes/Proceses.hpp"



class TaskManager {
private:
    std::vector<Proceses>allProcesses;
    std::unordered_map<int,std::string>taskLookUp;

public:
    void loadTasks();
    const std::vector<Proceses> getAllProcesses;
    std::unordered_map<int,std::string>& getTaskById(int pId) const;
    bool stopTask(int pId);
};



#endif //TASKMANAGER_H
