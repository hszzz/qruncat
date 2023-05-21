//
// Created by Shih He on 2023/5/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"

#include <QLabel>
#include <QDirIterator>
#include <QPushButton>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QSysInfo>

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent),
        canvas_(new QLabel),
        start_(new QPushButton),
        icon_(new QSystemTrayIcon),
        index_(0) {
    resize(100, 100);

    canvas_->setParent(this);
    canvas_->resize(16, 16);
    canvas_->move(42, 42);

    start_->setParent(this);
    start_->setText("start");
    start_->resize(80, 30);

    icon_->setParent(this);

    connect(start_, SIGNAL(clicked()), this, SLOT(start()));
}

void MainWindow::start() {
    QDirIterator it(":/themes/cat/", QStringList(), QDir::Files, QDirIterator::NoIteratorFlags);
    while (it.hasNext()) {
        QString filename = it.next();
        pics_.emplace_back(filename);
        icons_.emplace_back(filename);
    }

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(play()));
    icon_->show();
    timer->start(66);
}

void MainWindow::play() {
    canvas_->setPixmap(pics_[index_]);
    icon_->setIcon(icons_[index_]);
    index_ = ++index_ % pics_.size();
}

MainWindow::~MainWindow() = default;
