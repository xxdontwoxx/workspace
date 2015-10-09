/********************************************************************************
** Form generated from reading UI file 'link_pro.ui'
**
** Created: Mon Sep 28 09:27:19 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINK_PRO_H
#define UI_LINK_PRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_link_proClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *link_proClass)
    {
        if (link_proClass->objectName().isEmpty())
            link_proClass->setObjectName(QString::fromUtf8("link_proClass"));
        link_proClass->resize(600, 400);
        menuBar = new QMenuBar(link_proClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        link_proClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(link_proClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        link_proClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(link_proClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        link_proClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(link_proClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        link_proClass->setStatusBar(statusBar);

        retranslateUi(link_proClass);

        QMetaObject::connectSlotsByName(link_proClass);
    } // setupUi

    void retranslateUi(QMainWindow *link_proClass)
    {
        link_proClass->setWindowTitle(QApplication::translate("link_proClass", "link_pro", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class link_proClass: public Ui_link_proClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINK_PRO_H
