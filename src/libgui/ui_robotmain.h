/********************************************************************************
** Form generated from reading UI file 'robotmain.ui'
**
** Created: Sat Jan 4 20:39:33 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTMAIN_H
#define UI_ROBOTMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotMain
{
public:
    QAction *actionLoad_Config;
    QAction *actionExit;
    QWidget *centralWidget;
    QCheckBox *simulation;
    QCheckBox *plots;
    QCheckBox *remote;
    QCheckBox *visualization;
    QLineEdit *remoteadd;
    QSpinBox *port;
    QCheckBox *ethernet;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RobotMain)
    {
        if (RobotMain->objectName().isEmpty())
            RobotMain->setObjectName(QString::fromUtf8("RobotMain"));
        RobotMain->resize(219, 242);
        actionLoad_Config = new QAction(RobotMain);
        actionLoad_Config->setObjectName(QString::fromUtf8("actionLoad_Config"));
        actionExit = new QAction(RobotMain);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(RobotMain);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        simulation = new QCheckBox(centralWidget);
        simulation->setObjectName(QString::fromUtf8("simulation"));
        simulation->setGeometry(QRect(10, 120, 97, 22));
        plots = new QCheckBox(centralWidget);
        plots->setObjectName(QString::fromUtf8("plots"));
        plots->setGeometry(QRect(10, 150, 97, 22));
        remote = new QCheckBox(centralWidget);
        remote->setObjectName(QString::fromUtf8("remote"));
        remote->setGeometry(QRect(10, 60, 97, 22));
        visualization = new QCheckBox(centralWidget);
        visualization->setObjectName(QString::fromUtf8("visualization"));
        visualization->setGeometry(QRect(10, 90, 121, 21));
        remoteadd = new QLineEdit(centralWidget);
        remoteadd->setObjectName(QString::fromUtf8("remoteadd"));
        remoteadd->setGeometry(QRect(100, 60, 113, 21));
        port = new QSpinBox(centralWidget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(100, 30, 60, 21));
        ethernet = new QCheckBox(centralWidget);
        ethernet->setObjectName(QString::fromUtf8("ethernet"));
        ethernet->setGeometry(QRect(10, 30, 97, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 141, 16));
        RobotMain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RobotMain);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 219, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        RobotMain->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RobotMain);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RobotMain->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RobotMain);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RobotMain->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_Config);
        menuFile->addAction(actionExit);

        retranslateUi(RobotMain);

        QMetaObject::connectSlotsByName(RobotMain);
    } // setupUi

    void retranslateUi(QMainWindow *RobotMain)
    {
        RobotMain->setWindowTitle(QApplication::translate("RobotMain", "RobotMain", 0, QApplication::UnicodeUTF8));
        actionLoad_Config->setText(QApplication::translate("RobotMain", "Load Config", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("RobotMain", "Exit", 0, QApplication::UnicodeUTF8));
        simulation->setText(QApplication::translate("RobotMain", "Simulation", 0, QApplication::UnicodeUTF8));
        plots->setText(QApplication::translate("RobotMain", "Plots", 0, QApplication::UnicodeUTF8));
        remote->setText(QApplication::translate("RobotMain", "Remote", 0, QApplication::UnicodeUTF8));
        visualization->setText(QApplication::translate("RobotMain", "Visulaization", 0, QApplication::UnicodeUTF8));
        ethernet->setText(QApplication::translate("RobotMain", "Ethernet", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RobotMain", "Robot Connections", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("RobotMain", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RobotMain: public Ui_RobotMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTMAIN_H
