/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mwBattalion
{
public:
    QWidget *centralWidget;
    QTableWidget *twBattalion;
    QPushButton *pbSave;
    QLabel *lBattalionName;
    QMenuBar *menuBar;
    QMenu *menuDdd;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mwBattalion)
    {
        if (mwBattalion->objectName().isEmpty())
            mwBattalion->setObjectName(QStringLiteral("mwBattalion"));
        mwBattalion->resize(712, 300);
        centralWidget = new QWidget(mwBattalion);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        twBattalion = new QTableWidget(centralWidget);
        twBattalion->setObjectName(QStringLiteral("twBattalion"));
        twBattalion->setGeometry(QRect(20, 30, 481, 201));
        pbSave = new QPushButton(centralWidget);
        pbSave->setObjectName(QStringLiteral("pbSave"));
        pbSave->setGeometry(QRect(540, 30, 97, 31));
        lBattalionName = new QLabel(centralWidget);
        lBattalionName->setObjectName(QStringLiteral("lBattalionName"));
        lBattalionName->setGeometry(QRect(30, 0, 71, 23));
        mwBattalion->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mwBattalion);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 712, 28));
        menuDdd = new QMenu(menuBar);
        menuDdd->setObjectName(QStringLiteral("menuDdd"));
        mwBattalion->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mwBattalion);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mwBattalion->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mwBattalion);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mwBattalion->setStatusBar(statusBar);

        menuBar->addAction(menuDdd->menuAction());

        retranslateUi(mwBattalion);

        QMetaObject::connectSlotsByName(mwBattalion);
    } // setupUi

    void retranslateUi(QMainWindow *mwBattalion)
    {
        mwBattalion->setWindowTitle(QApplication::translate("mwBattalion", "MainWindow", nullptr));
        pbSave->setText(QApplication::translate("mwBattalion", "Read", nullptr));
        lBattalionName->setText(QString());
        menuDdd->setTitle(QApplication::translate("mwBattalion", "Ddd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mwBattalion: public Ui_mwBattalion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
