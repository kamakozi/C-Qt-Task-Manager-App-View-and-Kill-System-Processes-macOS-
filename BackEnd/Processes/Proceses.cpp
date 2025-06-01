
#include "Proceses.hpp"
#include <iostream>
#include <thread>
#include <unordered_map>

Proceses::Proceses(int taskId, std::string taskName): taskId(taskId), taskName(std::move(taskName)){};
std::vector<Proceses>processes;
std::unordered_map<int,std::string>allTasks;

