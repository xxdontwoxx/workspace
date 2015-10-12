/********************************************************************************
** Form generated from reading UI file 'SearchDlg.ui'
**
** Created: Mon Oct 12 14:03:39 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDLG_H
#define UI_SEARCHDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDlg
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QGroupBox *groupBox_2;
    QComboBox *mCmbField;
    QComboBox *mCmbCondition;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *mBtnOk;
    QPushButton *mBtnCancel;

    void setupUi(QDialog *SearchDlg)
    {
        if (SearchDlg->objectName().isEmpty())
            SearchDlg->setObjectName(QString::fromUtf8("SearchDlg"));
        SearchDlg->resize(456, 250);
        verticalLayoutWidget = new QWidget(SearchDlg);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 471, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 5, 5, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 20, 141, 181));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(170, 0, 269, 213));
        mCmbField = new QComboBox(groupBox_2);
        mCmbField->setObjectName(QString::fromUtf8("mCmbField"));
        mCmbField->setGeometry(QRect(80, 20, 151, 22));
        mCmbField->setEditable(true);
        mCmbCondition = new QComboBox(groupBox_2);
        mCmbCondition->setObjectName(QString::fromUtf8("mCmbCondition"));
        mCmbCondition->setEnabled(true);
        mCmbCondition->setGeometry(QRect(80, 60, 111, 22));
        mCmbCondition->setEditable(false);
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 100, 151, 20));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 31, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 60, 31, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 100, 31, 16));

        horizontalLayout_2->addWidget(groupBox);

        horizontalLayout_2->setStretch(0, 4);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mBtnOk = new QPushButton(verticalLayoutWidget);
        mBtnOk->setObjectName(QString::fromUtf8("mBtnOk"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mBtnOk->sizePolicy().hasHeightForWidth());
        mBtnOk->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(mBtnOk);

        mBtnCancel = new QPushButton(verticalLayoutWidget);
        mBtnCancel->setObjectName(QString::fromUtf8("mBtnCancel"));
        sizePolicy.setHeightForWidth(mBtnCancel->sizePolicy().hasHeightForWidth());
        mBtnCancel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(mBtnCancel);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 9);
        verticalLayout->setStretch(1, 1);

        retranslateUi(SearchDlg);
        QObject::connect(mBtnCancel, SIGNAL(clicked()), SearchDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SearchDlg);
    } // setupUi

    void retranslateUi(QDialog *SearchDlg)
    {
        SearchDlg->setWindowTitle(QApplication::translate("SearchDlg", "\346\225\260\346\215\256\345\272\223\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SearchDlg", "\346\237\245\350\257\242\345\257\271\350\261\241", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SearchDlg", "\346\237\245\350\257\242\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SearchDlg", "\345\255\227\346\256\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SearchDlg", "\345\205\263\347\263\273", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SearchDlg", "\345\200\274", 0, QApplication::UnicodeUTF8));
        mBtnOk->setText(QApplication::translate("SearchDlg", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        mBtnCancel->setText(QApplication::translate("SearchDlg", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SearchDlg: public Ui_SearchDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDLG_H
