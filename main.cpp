//
// Created by Shih He on 2023/5/21.
//
#include <QApplication>
#include <QPushButton>

#include "mainwindow.h"

int main(int argc, char** argv) {
    QApplication application(argc, argv);
    MainWindow window;
    window.show();
    return QApplication::exec();
}