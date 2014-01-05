#ifndef ROBOTVISION_H
#define ROBOTVISION_H

#include <QMainWindow>


namespace Ui {
class RobotVision;
}

class RobotVision : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RobotVision(QWidget *parent = 0);

    ~RobotVision();
    
private:
    Ui::RobotVision *ui;

};

#endif // ROBOTVISION_H
