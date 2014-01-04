#include "robotvision.h"
#include "ui_robotvision.h"

RobotVision::RobotVision(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RobotVision)
{
    ui->setupUi(this);
}

RobotVision::~RobotVision()
{
    delete ui;
}
