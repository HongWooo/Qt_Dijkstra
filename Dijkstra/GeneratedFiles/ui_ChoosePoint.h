/********************************************************************************
** Form generated from reading UI file 'ChoosePoint.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEPOINT_H
#define UI_CHOOSEPOINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoosePoint
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cb_start;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_chok;

    void setupUi(QWidget *ChoosePoint)
    {
        if (ChoosePoint->objectName().isEmpty())
            ChoosePoint->setObjectName(QStringLiteral("ChoosePoint"));
        ChoosePoint->resize(408, 109);
        verticalLayout = new QVBoxLayout(ChoosePoint);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ChoosePoint);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        cb_start = new QComboBox(ChoosePoint);
        cb_start->setObjectName(QStringLiteral("cb_start"));
        cb_start->setFont(font);

        horizontalLayout->addWidget(cb_start);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_chok = new QPushButton(ChoosePoint);
        btn_chok->setObjectName(QStringLiteral("btn_chok"));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(10);
        btn_chok->setFont(font1);

        horizontalLayout_2->addWidget(btn_chok);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ChoosePoint);

        QMetaObject::connectSlotsByName(ChoosePoint);
    } // setupUi

    void retranslateUi(QWidget *ChoosePoint)
    {
        ChoosePoint->setWindowTitle(QApplication::translate("ChoosePoint", "ChoosePoint", nullptr));
        label->setText(QApplication::translate("ChoosePoint", "\351\200\211\346\213\251\350\265\267\347\202\271", nullptr));
        btn_chok->setText(QApplication::translate("ChoosePoint", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoosePoint: public Ui_ChoosePoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEPOINT_H
