/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout_4;
    QLineEdit *li1x1;
    QLineEdit *li2x2;
    QLineEdit *li3x2;
    QLineEdit *li2x1;
    QLineEdit *li1x2;
    QLineEdit *li1x3;
    QLineEdit *li3x3;
    QLineEdit *li3x1;
    QLineEdit *li2x3;
    QHBoxLayout *horizontalLayout;
    QLabel *larank;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lirank;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ladeterminant;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lidet;
    QGridLayout *gridLayout_6;
    QPushButton *btrank;
    QPushButton *bttransponse;
    QPushButton *btinverse;
    QPushButton *btdeterminant;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 50, 482, 269));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        li1x1 = new QLineEdit(layoutWidget);
        li1x1->setObjectName(QString::fromUtf8("li1x1"));

        gridLayout_4->addWidget(li1x1, 0, 0, 1, 1);

        li2x2 = new QLineEdit(layoutWidget);
        li2x2->setObjectName(QString::fromUtf8("li2x2"));

        gridLayout_4->addWidget(li2x2, 1, 1, 1, 1);

        li3x2 = new QLineEdit(layoutWidget);
        li3x2->setObjectName(QString::fromUtf8("li3x2"));

        gridLayout_4->addWidget(li3x2, 2, 1, 1, 1);

        li2x1 = new QLineEdit(layoutWidget);
        li2x1->setObjectName(QString::fromUtf8("li2x1"));

        gridLayout_4->addWidget(li2x1, 1, 0, 1, 1);

        li1x2 = new QLineEdit(layoutWidget);
        li1x2->setObjectName(QString::fromUtf8("li1x2"));

        gridLayout_4->addWidget(li1x2, 0, 1, 1, 1);

        li1x3 = new QLineEdit(layoutWidget);
        li1x3->setObjectName(QString::fromUtf8("li1x3"));

        gridLayout_4->addWidget(li1x3, 0, 2, 1, 1);

        li3x3 = new QLineEdit(layoutWidget);
        li3x3->setObjectName(QString::fromUtf8("li3x3"));

        gridLayout_4->addWidget(li3x3, 2, 2, 1, 1);

        li3x1 = new QLineEdit(layoutWidget);
        li3x1->setObjectName(QString::fromUtf8("li3x1"));

        gridLayout_4->addWidget(li3x1, 2, 0, 1, 1);

        li2x3 = new QLineEdit(layoutWidget);
        li2x3->setObjectName(QString::fromUtf8("li2x3"));

        gridLayout_4->addWidget(li2x3, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        larank = new QLabel(layoutWidget);
        larank->setObjectName(QString::fromUtf8("larank"));

        horizontalLayout->addWidget(larank);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lirank = new QLineEdit(layoutWidget);
        lirank->setObjectName(QString::fromUtf8("lirank"));

        horizontalLayout->addWidget(lirank);


        gridLayout_5->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ladeterminant = new QLabel(layoutWidget);
        ladeterminant->setObjectName(QString::fromUtf8("ladeterminant"));

        horizontalLayout_2->addWidget(ladeterminant);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lidet = new QLineEdit(layoutWidget);
        lidet->setObjectName(QString::fromUtf8("lidet"));

        horizontalLayout_2->addWidget(lidet);


        gridLayout_5->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        btrank = new QPushButton(layoutWidget);
        btrank->setObjectName(QString::fromUtf8("btrank"));

        gridLayout_6->addWidget(btrank, 0, 0, 1, 1);

        bttransponse = new QPushButton(layoutWidget);
        bttransponse->setObjectName(QString::fromUtf8("bttransponse"));

        gridLayout_6->addWidget(bttransponse, 0, 1, 1, 1);

        btinverse = new QPushButton(layoutWidget);
        btinverse->setObjectName(QString::fromUtf8("btinverse"));

        gridLayout_6->addWidget(btinverse, 1, 0, 1, 1);

        btdeterminant = new QPushButton(layoutWidget);
        btdeterminant->setObjectName(QString::fromUtf8("btdeterminant"));

        gridLayout_6->addWidget(btdeterminant, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_6, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260", nullptr));
        larank->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\275\320\263 \320\274\320\260\321\202\321\200\320\270\321\206\321\213", nullptr));
        ladeterminant->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\214", nullptr));
        btrank->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \321\200\320\260\320\275\320\263", nullptr));
        bttransponse->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\260\320\275\321\201\320\277\320\276\320\275\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        btinverse->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\276\320\261\321\200\320\260\321\202\320\275\321\203\321\216", nullptr));
        btdeterminant->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
