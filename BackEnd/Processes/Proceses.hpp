//
// Created by ziga zoric on 01.06.25.
//

#ifndef PROCCESES_H
#define PROCCESES_H
#include <string>
#include <vector>



class Proceses {
private:
    int taskId;
    std::string taskName;

public:
    Proceses(int taskId,std::string taskName);
    [[nodiscard]]int getTaskId()const {
        return taskId;
    }
    [[nodiscard]] std::string getTaskName()const {
        return taskName;
    }



};



#endif //PROCCESES_H
