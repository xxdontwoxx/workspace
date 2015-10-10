/********************************************************************************
** Form generated from reading UI file 'link_pro.ui'
**
** Created: Sat Oct 10 14:19:08 2015
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
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_link_proClass
{
public:
    QAction *dbaction;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *link_proClass)
    {
        if (link_proClass->objectName().isEmpty())
            link_proClass->setObjectName(QString::fromUtf8("link_proClass"));
        link_proClass->resize(600, 400);
        dbaction = new QAction(link_proClass);
        dbaction->setObjectName(QString::fromUtf8("dbaction"));
        centralWidget = new QWidget(link_proClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        link_proClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(link_proClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        link_proClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(dbaction);

        retranslateUi(link_proClass);

        QMetaObject::connectSlotsByName(link_proClass);
    } // setupUi

    void retranslateUi(QMainWindow *link_proClass)
    {
        link_proClass->setWindowTitle(QApplication::translate("link_proClass", "link_pro", 0, QApplication::UnicodeUTF8));
        dbaction->setText(QApplication::translate("link_proClass", "\346\225\260\346\215\256\345\272\223\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("link_proClass", "\346\225\260\346\215\256\345\272\223", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class link_proClass: public Ui_link_proClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINK_PRO_H
