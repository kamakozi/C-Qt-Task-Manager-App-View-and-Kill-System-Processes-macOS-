#include "MainWindow.hpp"
#include <QtWidgets>
#include <QBoxLayout>
#include <QHeaderView>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <QMessageBox>
#include "../../BackEnd/GetProcesses/GetProcesses.h"

QWidget* MainWindow::createWindow() {
    QWidget *window = new QWidget;
    window->resize(680, 550);
    window->setWindowTitle("Memory Task Manager");

    QVBoxLayout *layout = new QVBoxLayout;


    QLineEdit* searchTask = new QLineEdit();
    searchTask->setPlaceholderText("Search by PID or name");
    layout->addWidget(searchTask);


    QTableWidget *table = new QTableWidget;
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"PID", "Name", "Action"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    layout->addWidget(table);


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

        QObject::connect(deleteButton, &QPushButton::clicked, [pId, table]() {
            if (kill(pId, SIGKILL) == 0) {
                std::cout << "Killed " << pId << "\n";
            } else {
                QMessageBox::critical(table, "Permission denied!", "Please run app in sudo: No permission error!");
                perror("Failed to kill");
            }
        });

        table->setCellWidget(row, 2, deleteButton);
        ++row;
    }

    QObject::connect(searchTask, &QLineEdit::textChanged, [table](const QString &text) {
        for (int i = 0; i < table->rowCount(); ++i) {
            QString pidText = table->item(i, 0)->text();
            QString nameText = table->item(i, 1)->text();

            bool match = pidText.contains(text, Qt::CaseInsensitive) ||
                         nameText.contains(text, Qt::CaseInsensitive);

            table->setRowHidden(i, !match);
        }
    });

    window->setLayout(layout);
    return window;
}