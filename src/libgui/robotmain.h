#ifndef ROBOTMAIN_H
#define ROBOTMAIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "ui_robotmain.h"

namespace Ui {
class RobotMain;
}

class RobotMain : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RobotMain(QWidget *parent = 0);
    //YOUBOTPYTHON::Robot *robot;
    ~RobotMain();
    
private slots:


    void on_ethernet_clicked();

    void on_visualization_clicked();

    void on_simulation_clicked();

private:
    Ui::RobotMain *ui;
};

#endif // ROBOTMAIN_H
