#include <QApplication>
#include "libgui/robotvision.h"

void init()
{
   
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RobotVision w;
    w.show();
    
    return a.exec();
}
