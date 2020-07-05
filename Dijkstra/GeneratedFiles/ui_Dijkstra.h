/********************************************************************************
** Form generated from reading UI file 'Dijkstra.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJKSTRA_H
#define UI_DIJKSTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DijkstraClass
{
public:
    QAction *action_edt;
    QAction *action_start;
    QAction *action_load;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *table;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_nextstep;
    QPushButton *btn_finish;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DijkstraClass)
    {
        if (DijkstraClass->objectName().isEmpty())
            DijkstraClass->setObjectName(QStringLiteral("DijkstraClass"));
        DijkstraClass->resize(962, 634);
        action_edt = new QAction(DijkstraClass);
        action_edt->setObjectName(QStringLiteral("action_edt"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Dijkstra/Resources/edit_24px_1208057_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_edt->setIcon(icon);
        action_start = new QAction(DijkstraClass);
        action_start->setObjectName(QStringLiteral("action_start"));
        action_start->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Dijkstra/Resources/flag_24.15444015444px_1227697_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_start->setIcon(icon1);
        action_load = new QAction(DijkstraClass);
        action_load->setObjectName(QStringLiteral("action_load"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Dijkstra/Resources/load.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_load->setIcon(icon2);
        centralWidget = new QWidget(DijkstraClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(672, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font.setPointSize(16);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        table = new QTableWidget(centralWidget);
        table->setObjectName(QStringLiteral("table"));

        verticalLayout->addWidget(table);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_nextstep = new QPushButton(centralWidget);
        btn_nextstep->setObjectName(QStringLiteral("btn_nextstep"));
        btn_nextstep->setEnabled(false);
        btn_nextstep->setMinimumSize(QSize(0, 48));
        btn_nextstep->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(btn_nextstep);

        btn_finish = new QPushButton(centralWidget);
        btn_finish->setObjectName(QStringLiteral("btn_finish"));
        btn_finish->setEnabled(false);
        btn_finish->setMinimumSize(QSize(0, 48));

        horizontalLayout->addWidget(btn_finish);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 3);
        DijkstraClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DijkstraClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 962, 26));
        DijkstraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DijkstraClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        DijkstraClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DijkstraClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DijkstraClass->setStatusBar(statusBar);

        mainToolBar->addAction(action_edt);
        mainToolBar->addAction(action_load);
        mainToolBar->addAction(action_start);

        retranslateUi(DijkstraClass);

        QMetaObject::connectSlotsByName(DijkstraClass);
    } // setupUi

    void retranslateUi(QMainWindow *DijkstraClass)
    {
        DijkstraClass->setWindowTitle(QApplication::translate("DijkstraClass", "Dijkstra\347\256\227\346\263\225\346\274\224\347\244\272", nullptr));
        action_edt->setText(QApplication::translate("DijkstraClass", "\347\274\226\350\276\221\345\233\276", nullptr));
        action_start->setText(QApplication::translate("DijkstraClass", "\351\200\211\346\213\251\350\265\267\347\202\271", nullptr));
        action_load->setText(QApplication::translate("DijkstraClass", "\345\212\240\350\275\275\345\233\276", nullptr));
        label->setText(QApplication::translate("DijkstraClass", "\350\277\207\347\250\213", nullptr));
        btn_nextstep->setText(QApplication::translate("DijkstraClass", "\344\270\213\344\270\200\346\255\245", nullptr));
        btn_finish->setText(QApplication::translate("DijkstraClass", "\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DijkstraClass: public Ui_DijkstraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJKSTRA_H
