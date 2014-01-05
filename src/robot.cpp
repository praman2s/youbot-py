#include <QApplication>
#include "libgui/robotmain.h"

void init()
{
   
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RobotMain m;
    m.show();
    
    return a.exec();
}
