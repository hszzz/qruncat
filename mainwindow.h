//
// Created by Shih He on 2023/5/21.
//

#ifndef QRUNCAT_MAINWINDOW_H
#define QRUNCAT_MAINWINDOW_H

#include <QWidget>
#include <vector>

class QLabel;
class QPushButton;
class QSystemTrayIcon;

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void start();
    void play();

private:
    QLabel* canvas_;
    QPushButton* start_;
    QSystemTrayIcon* icon_;

    std::vector<QPixmap> pics_;
    std::vector<QIcon> icons_;
    size_t index_;
};


#endif //QRUNCAT_MAINWINDOW_H
