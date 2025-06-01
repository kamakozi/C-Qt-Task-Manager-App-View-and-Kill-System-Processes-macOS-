#include <iostream>
#include "MainWindow/MainWindow.hpp"
#include <QApplication>

int main(int argc,char *argv[]) {
    QApplication app(argc,argv);

    MainWindow mw;
    QWidget* window =mw.createWindow();
    window->show();
    return app.exec();

}