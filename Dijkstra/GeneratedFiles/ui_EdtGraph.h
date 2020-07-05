/********************************************************************************
** Form generated from reading UI file 'EdtGraph.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDTGRAPH_H
#define UI_EDTGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EdtGraph
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ledt_vnum;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *edt_graphinfo;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_dlgok;
    QPushButton *btn_dlgrand;
    QPushButton *btn_dlgcancel;

    void setupUi(QDialog *EdtGraph)
    {
        if (EdtGraph->objectName().isEmpty())
            EdtGraph->setObjectName(QStringLiteral("EdtGraph"));
        EdtGraph->resize(317, 523);
        verticalLayout_2 = new QVBoxLayout(EdtGraph);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(EdtGraph);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        ledt_vnum = new QLineEdit(EdtGraph);
        ledt_vnum->setObjectName(QStringLiteral("ledt_vnum"));
        ledt_vnum->setMinimumSize(QSize(0, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(14);
        ledt_vnum->setFont(font1);

        horizontalLayout->addWidget(ledt_vnum);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        edt_graphinfo = new QPlainTextEdit(EdtGraph);
        edt_graphinfo->setObjectName(QStringLiteral("edt_graphinfo"));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Arabic"));
        font2.setPointSize(18);
        edt_graphinfo->setFont(font2);

        verticalLayout->addWidget(edt_graphinfo);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn_dlgok = new QPushButton(EdtGraph);
        btn_dlgok->setObjectName(QStringLiteral("btn_dlgok"));
        QFont font3;
        font3.setFamily(QStringLiteral("Adobe Arabic"));
        font3.setPointSize(12);
        btn_dlgok->setFont(font3);

        horizontalLayout_3->addWidget(btn_dlgok);

        btn_dlgrand = new QPushButton(EdtGraph);
        btn_dlgrand->setObjectName(QStringLiteral("btn_dlgrand"));
        btn_dlgrand->setFont(font3);

        horizontalLayout_3->addWidget(btn_dlgrand);

        btn_dlgcancel = new QPushButton(EdtGraph);
        btn_dlgcancel->setObjectName(QStringLiteral("btn_dlgcancel"));
        btn_dlgcancel->setFont(font3);

        horizontalLayout_3->addWidget(btn_dlgcancel);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(EdtGraph);

        QMetaObject::connectSlotsByName(EdtGraph);
    } // setupUi

    void retranslateUi(QDialog *EdtGraph)
    {
        EdtGraph->setWindowTitle(QApplication::translate("EdtGraph", "\347\274\226\350\276\221\345\233\276", nullptr));
        label->setText(QApplication::translate("EdtGraph", "\351\241\266\347\202\271\346\225\260", nullptr));
        btn_dlgok->setText(QApplication::translate("EdtGraph", "\347\241\256\345\256\232", nullptr));
        btn_dlgrand->setText(QApplication::translate("EdtGraph", "\351\232\217\346\234\272", nullptr));
        btn_dlgcancel->setText(QApplication::translate("EdtGraph", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdtGraph: public Ui_EdtGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDTGRAPH_H
