/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action1;
    QWidget *centralWidget;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *size;
    QRadioButton *size1;
    QRadioButton *size2;
    QWidget *path;
    QLabel *savefilename;
    QLineEdit *lineEdit;
    QPushButton *setsavepath;
    QGroupBox *groupBox;
    QPushButton *startrecord;
    QPushButton *stoprecord;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_time;
    QLabel *filepathname;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(506, 426);
        action1 = new QAction(MainWindow);
        action1->setObjectName(QStringLiteral("action1"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 320, 240));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"border: 1px solid black;\n"
"border-radius: 10;\n"
"}"));
        label->setFrameShape(QFrame::Box);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(340, 10, 151, 241));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::East);
        size = new QWidget();
        size->setObjectName(QStringLiteral("size"));
        size1 = new QRadioButton(size);
        size1->setObjectName(QStringLiteral("size1"));
        size1->setGeometry(QRect(10, 20, 89, 17));
        size2 = new QRadioButton(size);
        size2->setObjectName(QStringLiteral("size2"));
        size2->setGeometry(QRect(10, 40, 89, 17));
        tabWidget->addTab(size, QString());
        path = new QWidget();
        path->setObjectName(QStringLiteral("path"));
        savefilename = new QLabel(path);
        savefilename->setObjectName(QStringLiteral("savefilename"));
        savefilename->setGeometry(QRect(10, 20, 111, 16));
        lineEdit = new QLineEdit(path);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 101, 20));
        setsavepath = new QPushButton(path);
        setsavepath->setObjectName(QStringLiteral("setsavepath"));
        setsavepath->setGeometry(QRect(10, 70, 101, 21));
        tabWidget->addTab(path, QString());
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 260, 201, 51));
        groupBox->setStyleSheet(QLatin1String("QGroupBox{\n"
"border: 1px solid black;\n"
"border-radius: 10;\n"
"background-color: rgba(135,175,231,150);\n"
"}"));
        startrecord = new QPushButton(groupBox);
        startrecord->setObjectName(QStringLiteral("startrecord"));
        startrecord->setGeometry(QRect(10, 20, 75, 23));
        startrecord->setStyleSheet(QStringLiteral(""));
        stoprecord = new QPushButton(groupBox);
        stoprecord->setObjectName(QStringLiteral("stoprecord"));
        stoprecord->setGeometry(QRect(110, 20, 75, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 319, 421, 51));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox{\n"
"border: 1px solid black;\n"
"border-radius: 10;\n"
"background-color: rgba(135,175,231,150);\n"
"}"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 54, 12));
        label_time = new QLabel(groupBox_2);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(80, 20, 54, 12));
        filepathname = new QLabel(groupBox_2);
        filepathname->setObjectName(QStringLiteral("filepathname"));
        filepathname->setGeometry(QRect(150, 20, 181, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 506, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action1);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action1->setText(QApplication::translate("MainWindow", "about", 0));
        label->setText(QString());
        size1->setText(QApplication::translate("MainWindow", "320*240", 0));
        size2->setText(QApplication::translate("MainWindow", "480*640", 0));
        tabWidget->setTabText(tabWidget->indexOf(size), QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\244\247\345\260\217", 0));
        savefilename->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266\345\220\215\345\255\227\357\274\232", 0));
        setsavepath->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\344\277\235\345\255\230\350\267\257\345\276\204", 0));
        tabWidget->setTabText(tabWidget->indexOf(path), QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\226\207\344\273\266\345\220\215", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\275\225\345\210\266", 0));
        startrecord->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\275\225\345\210\266", 0));
        stoprecord->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\275\225\345\210\266", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\350\247\206\351\242\221\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\275\225\345\210\266\347\247\222\346\225\260\357\274\232", 0));
        label_time->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264", 0));
        filepathname->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\267\257\345\276\204", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
