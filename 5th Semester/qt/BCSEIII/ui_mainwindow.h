/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *Draw;
    QSpinBox *circle_radius;
    QRadioButton *draw_circle;
    QRadioButton *draw_line;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(999, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QStringLiteral("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 70, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 50, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QStringLiteral("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(720, 140, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(730, 120, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QStringLiteral("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QStringLiteral("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QStringLiteral("show_axes"));
        show_axes->setGeometry(QRect(720, 10, 91, 21));
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QStringLiteral("Draw"));
        Draw->setGeometry(QRect(710, 290, 101, 41));
        circle_radius = new QSpinBox(centralWidget);
        circle_radius->setObjectName(QStringLiteral("circle_radius"));
        circle_radius->setGeometry(QRect(790, 190, 46, 20));
        draw_circle = new QRadioButton(centralWidget);
        draw_circle->setObjectName(QStringLiteral("draw_circle"));
        draw_circle->setGeometry(QRect(710, 190, 81, 17));
        draw_line = new QRadioButton(centralWidget);
        draw_line->setObjectName(QStringLiteral("draw_line"));
        draw_line->setGeometry(QRect(710, 240, 77, 17));
        set_point1 = new QPushButton(centralWidget);
        set_point1->setObjectName(QStringLiteral("set_point1"));
        set_point1->setGeometry(QRect(790, 240, 81, 23));
        set_point2 = new QPushButton(centralWidget);
        set_point2->setObjectName(QStringLiteral("set_point2"));
        set_point2->setGeometry(QRect(880, 240, 81, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 340, 101, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "    Mouse Movement", 0));
        mouse_pressed->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", 0));
        show_axes->setText(QApplication::translate("MainWindow", "Show Axes", 0));
        Draw->setText(QApplication::translate("MainWindow", "Draw", 0));
        draw_circle->setText(QApplication::translate("MainWindow", "Draw Circle", 0));
        draw_line->setText(QApplication::translate("MainWindow", "Draw Line", 0));
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", 0));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", 0));
        pushButton->setText(QApplication::translate("MainWindow", "RESET", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
