cmake_minimum_required(VERSION 3.31)
project(taskmanager)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt/lib/cmake")
find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(taskmanager FrontEnd/main.cpp
        FrontEnd/MainWindow/MainWindow.cpp
        FrontEnd/MainWindow/MainWindow.hpp
        BackEnd/GetProcesses/GetProcesses.h
        BackEnd/GetProcesses/GetProcesses.cpp
        BackEnd/Processes/Proceses.cpp
        BackEnd/Processes/Proceses.hpp)


set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
target_link_libraries(taskmanager
        PRIVATE
        Qt6::Widgets)