#include "MainWindow.hpp"
#include <QtWidgets>
#include <QBoxLayout>
#include <QHeaderView>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "../../BackEnd/GetProcesses/GetProcesses.h"

QWidget* MainWindow::createWindow() {
    QWidget *window = new QWidget;
    window->resize(680, 550);
    window->setWindowTitle("Memory Task Manager");

    QVBoxLayout *layout = new QVBoxLayout;

    QTableWidget *table = new QTableWidget;
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"PID", "Name", "Action"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    GetProcesses gp;
    auto listOfTasks = gp.get_process();

    int row = 0;
    for (const auto& proc : listOfTasks) {
        table->insertRow(row);

        int pId = proc->getTaskId();
        std::string taskName = proc->getTaskName();

        table->setItem(row, 0, new QTableWidgetItem(QString::number(pId)));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(taskName)));

        QPushButton *deleteButton = new QPushButton("Stop");

        QObject::connect(deleteButton, &QPushButton::clicked, [pId]() {
            if (kill(pId, SIGKILL) == 0) {
                std::cout << "Killed " << pId << "\n";
            } else {
                perror("Failed to kill");
            }
        });

        table->setCellWidget(row, 2, deleteButton);
        ++row;
    }

    layout->addWidget(table);
    window->setLayout(layout);

    return window;
}