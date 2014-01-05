#include "robotmain.h"
#include "ui_robotmain.h"


RobotMain::RobotMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RobotMain)
{
    ui->setupUi(this);
}

RobotMain::~RobotMain()
{
    delete ui;
}



void RobotMain::on_ethernet_clicked()
{
    //youbot connection
    //QMessageBox::information(this,tr("Connection"),tr("Have a valid connection"));
    //robot = new Robot();
}

void RobotMain::on_visualization_clicked()
{
    //try rviz
}

void RobotMain::on_simulation_clicked()
{
    //openrave
}
