/********************************************************************************
** Form generated from reading UI file 'robotvision.ui'
**
** Created: Fri Jan 3 16:57:58 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTVISION_H
#define UI_ROBOTVISION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotVision
{
public:
    QAction *actionNew;
    QAction *actionHelp;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QTabWidget *propertiesTab;
    QWidget *probTab;
    QGridLayout *gridLayout;
    QTreeWidget *problemTree;
    QTabWidget *viewsTab;
    QWidget *introTab;
    QGridLayout *gridLayout1;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuActions;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *outputWindow;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout2;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *RobotVision)
    {
        if (RobotVision->objectName().isEmpty())
            RobotVision->setObjectName(QString::fromUtf8("RobotVision"));
        RobotVision->setWindowModality(Qt::ApplicationModal);
        RobotVision->resize(850, 759);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RobotVision->sizePolicy().hasHeightForWidth());
        RobotVision->setSizePolicy(sizePolicy);
        RobotVision->setMinimumSize(QSize(850, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/kautham.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        RobotVision->setWindowIcon(icon);
        RobotVision->setToolButtonStyle(Qt::ToolButtonIconOnly);
        RobotVision->setDockNestingEnabled(false);
        actionNew = new QAction(RobotVision);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionHelp = new QAction(RobotVision);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(RobotVision);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(RobotVision);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(600, 500));
        splitter->setOrientation(Qt::Horizontal);
        propertiesTab = new QTabWidget(splitter);
        propertiesTab->setObjectName(QString::fromUtf8("propertiesTab"));
        propertiesTab->setMaximumSize(QSize(250, 16777215));
        propertiesTab->setTabPosition(QTabWidget::West);
        propertiesTab->setTabShape(QTabWidget::Rounded);
        probTab = new QWidget();
        probTab->setObjectName(QString::fromUtf8("probTab"));
        gridLayout = new QGridLayout(probTab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        problemTree = new QTreeWidget(probTab);
        problemTree->setObjectName(QString::fromUtf8("problemTree"));

        gridLayout->addWidget(problemTree, 0, 0, 1, 1);

        propertiesTab->addTab(probTab, QString());
        splitter->addWidget(propertiesTab);
        viewsTab = new QTabWidget(splitter);
        viewsTab->setObjectName(QString::fromUtf8("viewsTab"));
        viewsTab->setEnabled(true);
        viewsTab->setMinimumSize(QSize(600, 4));
        introTab = new QWidget();
        introTab->setObjectName(QString::fromUtf8("introTab"));
        introTab->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(introTab->sizePolicy().hasHeightForWidth());
        introTab->setSizePolicy(sizePolicy1);
        gridLayout1 = new QGridLayout(introTab);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        textBrowser = new QTextBrowser(introTab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setSource(QUrl(QString::fromUtf8("")));
        textBrowser->setOpenExternalLinks(true);

        gridLayout1->addWidget(textBrowser, 0, 0, 1, 1);

        viewsTab->addTab(introTab, QString());
        splitter->addWidget(viewsTab);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        RobotVision->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RobotVision);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 25));
        menuActions = new QMenu(menubar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        RobotVision->setMenuBar(menubar);
        statusbar = new QStatusBar(RobotVision);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RobotVision->setStatusBar(statusbar);
        toolBar = new QToolBar(RobotVision);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setOrientation(Qt::Horizontal);
        RobotVision->addToolBar(Qt::TopToolBarArea, toolBar);
        outputWindow = new QDockWidget(RobotVision);
        outputWindow->setObjectName(QString::fromUtf8("outputWindow"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(outputWindow->sizePolicy().hasHeightForWidth());
        outputWindow->setSizePolicy(sizePolicy2);
        outputWindow->setMinimumSize(QSize(125, 69));
        outputWindow->setBaseSize(QSize(122, 69));
        outputWindow->setAutoFillBackground(false);
        outputWindow->setFloating(false);
        outputWindow->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        outputWindow->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidgetContents->setMinimumSize(QSize(100, 69));
        gridLayout2 = new QGridLayout(dockWidgetContents);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        textEdit = new QTextEdit(dockWidgetContents);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy2.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy2);
        textEdit->setMinimumSize(QSize(50, 50));
        textEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout2->addWidget(textEdit, 0, 0, 1, 1);

        outputWindow->setWidget(dockWidgetContents);
        RobotVision->addDockWidget(static_cast<Qt::DockWidgetArea>(8), outputWindow);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuActions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(RobotVision);

        propertiesTab->setCurrentIndex(0);
        viewsTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RobotVision);
    } // setupUi

    void retranslateUi(QMainWindow *RobotVision)
    {
        RobotVision->setWindowTitle(QApplication::translate("RobotVision", "Robot Vision 1.0", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("RobotVision", "New...", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("RobotVision", "Kautham Planner", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("RobotVision", "About...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        propertiesTab->setAccessibleName(QApplication::translate("RobotVision", "l", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        QTreeWidgetItem *___qtreewidgetitem = problemTree->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("RobotVision", "Values", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("RobotVision", "Attributes", 0, QApplication::UnicodeUTF8));
        propertiesTab->setTabText(propertiesTab->indexOf(probTab), QApplication::translate("RobotVision", "Problem", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("RobotVision", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        viewsTab->setTabText(viewsTab->indexOf(introTab), QApplication::translate("RobotVision", "Introduction", 0, QApplication::UnicodeUTF8));
        menuActions->setTitle(QApplication::translate("RobotVision", "Actions", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("RobotVision", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("RobotVision", "Help", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        outputWindow->setToolTip(QApplication::translate("RobotVision", "Output Window", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        outputWindow->setWindowTitle(QApplication::translate("RobotVision", "Output", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RobotVision: public Ui_RobotVision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTVISION_H
