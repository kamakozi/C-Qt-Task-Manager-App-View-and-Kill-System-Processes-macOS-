//
// Created by ziga zoric on 01.06.25.
//

#ifndef GETPROCESSES_H
#define GETPROCESSES_H
#include <memory>
#include "../Processes/Proceses.hpp"


class GetProcesses {
public:
    std::vector<std::unique_ptr<Proceses>>get_process();
};



#endif //GETPROCESSES_H
