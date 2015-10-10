/********************************************************************************
** Form generated from reading UI file 'dbview.ui'
**
** Created: Sat Oct 10 14:30:53 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBVIEW_H
#define UI_DBVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBView
{
public:
    QTableView *tableView;
    QListWidget *listWidget;

    void setupUi(QWidget *DBView)
    {
        if (DBView->objectName().isEmpty())
            DBView->setObjectName(QString::fromUtf8("DBView"));
        DBView->resize(499, 391);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DBView->sizePolicy().hasHeightForWidth());
        DBView->setSizePolicy(sizePolicy);
        tableView = new QTableView(DBView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(150, 0, 351, 391));
        listWidget = new QListWidget(DBView);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 151, 391));

        retranslateUi(DBView);

        QMetaObject::connectSlotsByName(DBView);
    } // setupUi

    void retranslateUi(QWidget *DBView)
    {
        DBView->setWindowTitle(QApplication::translate("DBView", "DBView", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DBView: public Ui_DBView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBVIEW_H
