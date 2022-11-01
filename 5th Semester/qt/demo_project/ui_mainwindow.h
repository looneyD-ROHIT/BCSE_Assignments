/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
    QSpinBox *spinBox;
    QPushButton *pushButton_shGrid;
    QPushButton *pushButton_2;
    QPushButton *bresenhamLine;
    QPushButton *polarCircle;
    QPushButton *bresenhamCircle;
    QPushButton *polarEllipse;
    QSpinBox *xaxisRadius;
    QSpinBox *yaxisRadius;
    QLabel *label;
    QLabel *label_2;
    QPushButton *midpointEllispse;
    QPushButton *scanLineFill;
    QPushButton *setVertex;
    QPushButton *clearVertex;
    QPushButton *boundaryFill;
    QComboBox *fill_selector;
    QPushButton *floodfill;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1030, 804);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setCursor(QCursor(Qt::CrossCursor));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QString::fromUtf8("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 70, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(720, 50, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QString::fromUtf8("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(720, 140, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(730, 120, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QString::fromUtf8("show_axes"));
        show_axes->setGeometry(QRect(720, 10, 91, 21));
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QString::fromUtf8("Draw"));
        Draw->setGeometry(QRect(710, 290, 101, 41));
        circle_radius = new QSpinBox(centralWidget);
        circle_radius->setObjectName(QString::fromUtf8("circle_radius"));
        circle_radius->setGeometry(QRect(790, 190, 46, 20));
        draw_circle = new QRadioButton(centralWidget);
        draw_circle->setObjectName(QString::fromUtf8("draw_circle"));
        draw_circle->setGeometry(QRect(710, 190, 81, 17));
        draw_line = new QRadioButton(centralWidget);
        draw_line->setObjectName(QString::fromUtf8("draw_line"));
        draw_line->setGeometry(QRect(710, 240, 77, 17));
        set_point1 = new QPushButton(centralWidget);
        set_point1->setObjectName(QString::fromUtf8("set_point1"));
        set_point1->setGeometry(QRect(790, 232, 91, 31));
        set_point2 = new QPushButton(centralWidget);
        set_point2->setObjectName(QString::fromUtf8("set_point2"));
        set_point2->setGeometry(QRect(900, 232, 91, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(710, 340, 101, 41));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(710, 400, 61, 31));
        pushButton_shGrid = new QPushButton(centralWidget);
        pushButton_shGrid->setObjectName(QString::fromUtf8("pushButton_shGrid"));
        pushButton_shGrid->setGeometry(QRect(849, 67, 91, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(830, 290, 91, 41));
        bresenhamLine = new QPushButton(centralWidget);
        bresenhamLine->setObjectName(QString::fromUtf8("bresenhamLine"));
        bresenhamLine->setGeometry(QRect(830, 340, 91, 41));
        polarCircle = new QPushButton(centralWidget);
        polarCircle->setObjectName(QString::fromUtf8("polarCircle"));
        polarCircle->setGeometry(QRect(830, 400, 101, 41));
        bresenhamCircle = new QPushButton(centralWidget);
        bresenhamCircle->setObjectName(QString::fromUtf8("bresenhamCircle"));
        bresenhamCircle->setGeometry(QRect(710, 450, 91, 41));
        polarEllipse = new QPushButton(centralWidget);
        polarEllipse->setObjectName(QString::fromUtf8("polarEllipse"));
        polarEllipse->setGeometry(QRect(830, 520, 101, 31));
        xaxisRadius = new QSpinBox(centralWidget);
        xaxisRadius->setObjectName(QString::fromUtf8("xaxisRadius"));
        xaxisRadius->setGeometry(QRect(710, 520, 42, 22));
        yaxisRadius = new QSpinBox(centralWidget);
        yaxisRadius->setObjectName(QString::fromUtf8("yaxisRadius"));
        yaxisRadius->setGeometry(QRect(710, 550, 42, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(760, 520, 37, 12));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(760, 550, 37, 12));
        midpointEllispse = new QPushButton(centralWidget);
        midpointEllispse->setObjectName(QString::fromUtf8("midpointEllispse"));
        midpointEllispse->setGeometry(QRect(830, 560, 101, 31));
        scanLineFill = new QPushButton(centralWidget);
        scanLineFill->setObjectName(QString::fromUtf8("scanLineFill"));
        scanLineFill->setGeometry(QRect(710, 660, 81, 31));
        setVertex = new QPushButton(centralWidget);
        setVertex->setObjectName(QString::fromUtf8("setVertex"));
        setVertex->setGeometry(QRect(710, 620, 81, 31));
        clearVertex = new QPushButton(centralWidget);
        clearVertex->setObjectName(QString::fromUtf8("clearVertex"));
        clearVertex->setGeometry(QRect(800, 620, 81, 31));
        boundaryFill = new QPushButton(centralWidget);
        boundaryFill->setObjectName(QString::fromUtf8("boundaryFill"));
        boundaryFill->setGeometry(QRect(800, 660, 81, 31));
        fill_selector = new QComboBox(centralWidget);
        fill_selector->addItem(QString());
        fill_selector->addItem(QString());
        fill_selector->setObjectName(QString::fromUtf8("fill_selector"));
        fill_selector->setGeometry(QRect(890, 620, 71, 31));
        floodfill = new QPushButton(centralWidget);
        floodfill->setObjectName(QString::fromUtf8("floodfill"));
        floodfill->setGeometry(QRect(890, 660, 81, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        show_axes->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        Draw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        draw_circle->setText(QCoreApplication::translate("MainWindow", "Draw Circle", nullptr));
        draw_line->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        set_point1->setText(QCoreApplication::translate("MainWindow", "Set point 1", nullptr));
        set_point2->setText(QCoreApplication::translate("MainWindow", "Set point 2", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        pushButton_shGrid->setText(QCoreApplication::translate("MainWindow", "GRID", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Draw DDA Line", nullptr));
        bresenhamLine->setText(QCoreApplication::translate("MainWindow", "Draw Bresenham Line", nullptr));
        polarCircle->setText(QCoreApplication::translate("MainWindow", "Draw Polar Circle", nullptr));
        bresenhamCircle->setText(QCoreApplication::translate("MainWindow", "Bresenham Circle", nullptr));
        polarEllipse->setText(QCoreApplication::translate("MainWindow", "Polar Ellipse", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X radius", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y radius", nullptr));
        midpointEllispse->setText(QCoreApplication::translate("MainWindow", "MidPoint Ellipse", nullptr));
        scanLineFill->setText(QCoreApplication::translate("MainWindow", "ScanLine Fill", nullptr));
        setVertex->setText(QCoreApplication::translate("MainWindow", "SetVertex", nullptr));
        clearVertex->setText(QCoreApplication::translate("MainWindow", "ClearVertex", nullptr));
        boundaryFill->setText(QCoreApplication::translate("MainWindow", "Boundary Fill", nullptr));
        fill_selector->setItemText(0, QCoreApplication::translate("MainWindow", "4 point fill", nullptr));
        fill_selector->setItemText(1, QCoreApplication::translate("MainWindow", "8 point fill", nullptr));

        floodfill->setText(QCoreApplication::translate("MainWindow", "FloodFill", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
