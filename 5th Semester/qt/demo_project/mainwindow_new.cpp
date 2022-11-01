#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

int gs = 1;
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::point(int x,int y, int r, int g, int b) {

    if(gs == 1) img.setPixel(x,y,qRgb(r,g,b));
    else {
    //getting the frame heights and widths
    int frame_width = ui->frame->width();
    int frame_height = ui->frame->height();

    x = (x/gs)*gs;
    y = (y/gs)*gs;

    for(int x_coordinate=x+1;x_coordinate <  x + gs;x_coordinate++) {
        for(int y_coordinate=y+1;y_coordinate < y + gs;y_coordinate++) {
        //condition check to prevent coordinates from going out of bounds
            if (x_coordinate < frame_width && y_coordinate < frame_height)
                img.setPixel(x_coordinate,y_coordinate,qRgb(r,g,b));
            }
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::showMousePosition(QPoint &pos) {
    int x = (pos.x() - ui->frame->width()/2)/gs;
    int y = (ui->frame->height()/2 - pos.y())/gs;
    ui->mouse_movement->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
}
void MainWindow::Mouse_Pressed() {
    int x = (ui->frame->x - ui->frame->width()/2)/gs;
    int y = (ui->frame->height()/2 - ui->frame->y)/gs;
    ui->mouse_pressed->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
    point(ui->frame->x,ui->frame->y, 255, 0, 0);
}

void MainWindow::on_show_axes_clicked() {
    gs = ui->spinBox->value();
    int frame_width = ui->frame->width();
        int frame_height = ui->frame->height();

        if(ui->show_axes->isChecked()) {
            for(int j=0;j<frame_width;j+=gs) {
                point((img.width()/2),j, 0, 128, 0);
            }
            for(int i=0;i<= frame_height;i+=gs) {
                point(i,(img.height()/2), 0, 0, 128);
            }
        }
        else{
            for(int j=0;j<frame_width;j+=gs) {
                point((img.width()/2),j, 0, 0, 0);
            }
            for(int i=0;i<= frame_height;i+=gs) {
                point(i,(img.height()/2), 0, 0, 0);
            }
        }
}

void MainWindow::on_set_point1_clicked() {
    if(ui->draw_line->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
    }
}

void MainWindow::on_set_point2_clicked() {
    if(ui->draw_line->isChecked()){
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);
    }
}

void MainWindow::on_Draw_clicked() {
    int r0=ui->circle_radius->value();
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    if(ui->draw_circle->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        painter.setPen(pen);
        painter.drawEllipse(p1,r0,r0);
    }
    if(ui->draw_line->isChecked()){
        painter.setPen(Qt::red);
        painter.drawLine(p1,p2);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked() {
    for(int j=0;j<img.height();j++) {
        for(int i=0;i<img.width();i++) {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_shGrid_clicked(){
    gs = ui->spinBox->value();
    for(int j=0;j<img.height();j+=gs) {
        for(int i=0;i<img.width();i++) {
            img.setPixel(i,j,qRgb(255,255,255));
            img.setPixel(j,i,qRgb(255,255,255));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_spinBox_valueChanged(int arg1){
    on_pushButton_clicked();
    on_pushButton_shGrid_clicked();
    if(ui->show_axes->isChecked()){
        on_show_axes_clicked();
    }
}

