//
// Created by Shih He on 2023/5/21.
//
#include <QApplication>
#include <QPushButton>

int main(int argc, char** argv) {
    QApplication application(argc, argv);
    QPushButton button("123");
    button.resize(100, 300);
    button.show();
    return QApplication::exec();
}