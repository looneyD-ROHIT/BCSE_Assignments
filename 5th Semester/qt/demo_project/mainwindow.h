#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QTableView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_Draw_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_pushButton_clicked();
    //void on_show_grid_clicked();

    void on_pushButton_shGrid_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void drawDDALine (int r, int g, int b);

    void on_bresenhamLine_clicked();

    void on_polarCircle_clicked();

    void delay(int);

    void on_bresenhamCircle_clicked();

    void on_polarEllipse_clicked();


    void on_midpointEllispse_clicked();

    void storeEdgeInTable (int x1,int y1, int x2, int y2);

    void on_setVertex_clicked();
    void on_clearVertex_clicked();
    void initEdgeTable();
    void on_scanLineFill_clicked();

    void on_boundaryFill_clicked();
    void boundaryfillUtility8point (int x, int y, QRgb edgecolor, int r, int g, int b);
    void boundaryfillUtility4point (int x, int y, QRgb edgecolor, int r, int g, int b);

    void on_floodfill_clicked();
    void floodfillUtility4point (int x, int y, int r, int g, int b);
    void floodfillUtility8point (int x, int y, int r, int g, int b);


//    void on_fill_selector_activated(int index);

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int,int,int,int,int);
};

#endif // MAINWINDOW_H
