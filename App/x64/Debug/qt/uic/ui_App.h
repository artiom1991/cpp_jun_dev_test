/********************************************************************************
** Form generated from reading UI file 'App.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AppClass)
    {
        if (AppClass->objectName().isEmpty())
            AppClass->setObjectName("AppClass");
        AppClass->resize(600, 400);
        menuBar = new QMenuBar(AppClass);
        menuBar->setObjectName("menuBar");
        AppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AppClass);
        mainToolBar->setObjectName("mainToolBar");
        AppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AppClass);
        centralWidget->setObjectName("centralWidget");
        AppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AppClass);
        statusBar->setObjectName("statusBar");
        AppClass->setStatusBar(statusBar);

        retranslateUi(AppClass);

        QMetaObject::connectSlotsByName(AppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppClass)
    {
        AppClass->setWindowTitle(QCoreApplication::translate("AppClass", "App", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppClass: public Ui_AppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
