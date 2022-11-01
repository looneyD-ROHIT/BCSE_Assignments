//including the necessary header files
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <QThread>
#include <cmath>
#include<bits/stdc++.h>
#include <QTimer>
#include <QDebug>
#define maxHt 1800
#define maxVer 10000

using namespace std;
using namespace std::chrono;

int sum_x=0, sum_y=0, cnt=0;

QImage img=QImage(700,700,QImage::Format_RGB888);
std::vector<std::pair<int, int>> vertex_list;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));

    ui->fill_selector->addItem("8 point fill");
    ui->fill_selector->addItem ("4 point fill");
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


void MainWindow::on_pushButton_2_clicked()
{
    drawDDALine(255,255,0);
}

//implementation of the DDA Algorithm
void MainWindow::drawDDALine (int r, int g, int b){
       // (x0, y0) -> point1 ; (xn, yn) -> point 2
       double x0 = p1.x() / gs;
       double xn = p2.x() / gs;
       double y0 = p1.y() / gs;
       double yn = p2.y() / gs;

       //required for evaluating the step count in the algorithm
       double dx = fabs(xn - x0);
       double dy = fabs(yn - y0);

       double Dx, Dy;

       if (dx > dy ) { //y coordinate will increase backward or forward by the slope value
           Dx = 1;
           Dy = dy / dx;
       }

       else { // x coordinate will increase backward or forward by the inverse slope value
           Dx = dx / dy;
           Dy = 1;
       }
       //change the direction of movement accordingly
       if (x0 > xn) Dx *= -1;
       if (y0 > yn) Dy *= -1;

       double x = x0*gs + gs / 2; //adjusting the initial x coordinate according to the grid size
       double y = y0*gs + gs / 2; //adjusting the initial y coordinate according to the grid size

       auto start = high_resolution_clock::now(); //start the timer

       for (int steps =0; steps <= (dx > dy ? dx : dy); steps++) {
           point (x, y, r, g, b);
           x += Dx * gs;
           y += Dy * gs;
       }
       auto end = high_resolution_clock::now(); //end the timer for final time evaluation

       auto duration = duration_cast<microseconds>(end - start);
       long executionTime = duration.count();
       std::cout << "Execution time for DDA Algorithm :- " << executionTime << "\n";
}


void MainWindow::on_bresenhamLine_clicked()
{
        //(x0, y0) -> point1 ; (xn, yn) -> point2
        int x0 = p1.x()/gs;
        int y0 = p1.y()/gs;
        int xn = p2.x()/gs;
        int yn = p2.y()/gs;

        //required for evaluating the step count of the algorithm
        int dx = fabs(xn - x0);
        int dy = fabs(yn - y0);

        int Dx = (x0 > xn ? -1 : 1);
        int Dy = (y0 > yn ? -1 : 1);
        bool flag = 1;
        int x = x0*gs + gs/2; //adjusting the initial x coordinate according to the grid size
        int y = y0*gs + gs/2; //adjusting the initial y coordinate according to the grid size
        if(dy > dx) { // if slope > 1, then swap the elements
            swap(dx,dy);
            swap(x,y);
            swap(Dx,Dy);
            flag = 0;
        }

        //evauating the decision for pixel illumination
        int decision = 2*dy - dx;

        auto start = high_resolution_clock::now();
        //evaluating the algorithm

        for(int steps=0;steps<=dx;steps++) {
            if(flag) {
                point(x,y,255,0,0);
            }

            else point(y,x,255,0,0);

            if(decision < 0) {
                x += Dx*gs;
                decision += 2*dy;
            } else {
                x += Dx*gs;
                y += Dy*gs;
                decision += 2*dy - 2*dx;
            }
            //delay(1);
        }
        auto end = high_resolution_clock::now();
        long timeOfExecution = duration_cast<microseconds>(end - start).count();
        cout << "Execution Time for Bresenham's Algorithm :- " << timeOfExecution << "\n";
}


void MainWindow::on_polarCircle_clicked()
{
    p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);

        int x_center = p1.x();
        int y_center = p1.y();

        int radius = ui->circle_radius->value();
        for (int theta_degrees = 0; theta_degrees <= 45; theta_degrees++) {
            double theta_radians = M_PI * theta_degrees / 180;
            int xk = radius * cos (theta_radians) * gs;
            int yk = radius * sin (theta_radians) * gs;
            point (x_center + xk, y_center + yk, 255, 0, 0);
            point (x_center + xk, y_center - yk, 255, 0, 0);
            point (x_center - xk, y_center + yk, 255, 0, 0);
            point (x_center - xk, y_center - yk, 255, 0, 0);

            point (x_center + yk, y_center + xk, 255, 0, 0);
            point (x_center + yk, y_center - xk, 255, 0, 0);
            point (x_center - yk, y_center + xk, 255, 0, 0);
            point (x_center - yk, y_center - xk, 255, 0, 0);
            delay(1);
        }
}


//delay function to introduce animation while drawing
void MainWindow::delay(int n) {
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MainWindow::on_bresenhamCircle_clicked()
{
    int radius = ui->circle_radius->value();
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);

    int x0 = p1.x()/gs;
    int y0 = p1.y()/gs;
    x0 = x0*gs + gs/2;
    y0 = y0*gs + gs/2;

    int x = 0;
    int y = radius *gs;
    int p = (3 - 2*radius)*gs;
    auto start = high_resolution_clock::now();
    while(y > x) {
        point(x0 - x, y0 - y, 255, 0, 0);
        point(x0 + x, y0 - y, 255, 0, 0);
        point(x0 - x, y0 + y, 255, 0, 0);
        point(x0 + x, y0 + y, 255, 0, 0);
        point(x0 - y, y0 - x, 255, 0, 0);
        point(x0 + y, y0 - x, 255, 0, 0);
        point(x0 - y, y0 + x, 255, 0, 0);
        point(x0 + y, y0 + x, 255, 0, 0);

        x += gs;
        if(p <= 0) {
            p += 4*x + 6;
        } else {
            p += 4*(x-y) + 10;
            y -= gs;
        }
        delay(1);
    }
    auto end = high_resolution_clock::now();
    int executionTime = duration_cast<microseconds>(end - start).count();
    cout << "Execution Time for bresenham's circle drawing algorithm :- " << executionTime << "\n";
}


void MainWindow::on_polarEllipse_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);

    int x_center = p1.x();
    int y_center = p1.y();

    int a = ui->xaxisRadius->value();
    int b = ui->yaxisRadius->value();

    float theta1 = 0.0;
    float theta2 = 90.0;

    while (theta1 < theta2) {
        int xk = a * cos(theta1) * gs;
        int yk = b * sin (theta1) * gs;

        //plotting the polar coordinates on the grid
        point (x_center + xk, y_center + yk, 255, 0, 0);
        point (x_center - xk, y_center + yk, 255, 0, 0);
        point (x_center - xk, y_center - yk, 255, 0, 0);
        point (x_center + xk, y_center - yk, 255, 0, 0);

        theta1++;
        delay(1);//introducing a delay for animation effect
    }
}


void MainWindow::on_midpointEllispse_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
    int x_radius = ui->xaxisRadius->value();
    int y_radius = ui->yaxisRadius->value();
    int x_centre=p1.x();
    int y_centre=p1.y();

    //scaling up the center of the ellipse according to the gs
    x_centre=(x_centre/gs)*gs+gs/2;
    y_centre=(y_centre/gs)*gs+gs/2;

    int x=0;
    int y=y_radius;
    int px=0.0;
    int py=2 * (x_radius * x_radius)*y;
    //For first region
    int p1= (y_radius * y_radius) - (x_radius * x_radius * y_radius) +(0.25)* (x_radius * x_radius); //Initial value of decision paramemter

    while(px<py)
    {
        point(x_centre+x*gs,y_centre+y*gs, 255, 255, 0);
        point(x_centre-x*gs,y_centre+y*gs, 255, 255, 0);
        point(x_centre-x*gs,y_centre-y*gs, 255, 255, 0);
        point(x_centre+x*gs,y_centre-y*gs, 255, 255, 0);

        x++;
        px+=(2 * y_radius * y_radius);
        if(p1>=0) {
            y--;
            py-=(2 * x_radius * x_radius);
            p1=p1+(y_radius * y_radius)+px-py;

        }  else{
            p1=p1+(y_radius * y_radius)+px;
        }
        delay(1); //introducing a delay for enabling lazy loading
    }

    //For second region
    p1=(y_radius * y_radius) *((double)x+0.5)*((double)x+0.5)+(x_radius * x_radius)*(y-1)*(y-1)-(x_radius * x_radius)*(y_radius * y_radius); //Initial value of decision paramemter


    while(y>=0)
    {
        point(x_centre+x*gs,y_centre+y*gs, 255, 255, 0);
        point(x_centre-x*gs,y_centre+y*gs, 255, 255, 0);
        point(x_centre-x*gs,y_centre-y*gs, 255, 255, 0);
        point(x_centre+x*gs,y_centre-y*gs, 255, 255, 0);

        y--;
        py-=(x_radius * x_radius);
        if(p1<=0){
            x++;
            px+=(y_radius * y_radius);
            p1=p1+(x_radius * x_radius)-py+px;

        }  else  {
            p1=p1+(x_radius * x_radius)-py;
        }
        delay(1); //introducing a delay for enabling lazy loading
    }
}

typedef struct edgebucket{
    int ymax;   //max y-coordinate of edge
    float xofymin;  //x-coordinate of lowest edge point updated only in aet
    float slopeinverse;
}EdgeBucket;

typedef struct edgetabletup{
    // the array will give the scanline number
    // The edge table (ET) with edges entries sorted
    // in increasing y and x of the lower end

    int countEdgeBucket;    //no. of edgebuckets
    EdgeBucket buckets[maxVer];
}EdgeTableTuple;

EdgeTableTuple EdgeTable[maxHt];
EdgeTableTuple ActiveEdgeTuple;

void insertionSort(EdgeTableTuple *ett){
    int i,j;
    EdgeBucket temp;
    for (i = 1; i < ett->countEdgeBucket; i++){
        temp.ymax = ett->buckets[i].ymax;
        temp.xofymin = ett->buckets[i].xofymin;
        temp.slopeinverse = ett->buckets[i].slopeinverse;
        j = i - 1;

        while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0)){
            ett->buckets[j + 1].ymax = ett->buckets[j].ymax;
            ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin;
            ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
            j = j - 1;
        }
        ett->buckets[j + 1].ymax = temp.ymax;
        ett->buckets[j + 1].xofymin = temp.xofymin;
        ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
    }
}

void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv){
    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym;
    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm;
    (receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv;

    insertionSort(receiver);
    (receiver->countEdgeBucket)++;
}

void MainWindow::storeEdgeInTable (int x1,int y1, int x2, int y2){
    float m,minv;
    int ymaxTS,xwithyminTS, scanline;
    if (x2==x1){
        minv=0.000000;
    }else{
        m = ((float)(y2-y1))/((float)(x2-x1));
        if (y2==y1)
            return;
        minv = (float)1.0/m;
    }
    if (y1>y2){
        scanline=y2;
        ymaxTS=y1;
        xwithyminTS=x2;
    }else{
        scanline=y1;
        ymaxTS=y2;
        xwithyminTS=x1;
    }
    storeEdgeInTuple(&EdgeTable[scanline],ymaxTS,xwithyminTS,minv);
}

void MainWindow::on_setVertex_clicked(){
    vertex_list.push_back(std::make_pair((ui->frame->x/gs)*gs+gs/2,(ui->frame->y/gs)*gs+gs/2));
    sum_x += vertex_list.back().first;
    sum_y += vertex_list.back().second;
    cnt += 1;
    int i=vertex_list.size();
    if(i>=2){
        storeEdgeInTable(vertex_list[i-2].first, vertex_list[i-2].second, vertex_list[i-1].first, vertex_list[i-1].second);//storage of edges in edge table.
        p1.setX(vertex_list[i-1].first);p1.setY(vertex_list[i-1].second);
        p2.setX(vertex_list[i-2].first);p2.setY(vertex_list[i-2].second);
        on_pushButton_2_clicked();
    }
}


void MainWindow::on_clearVertex_clicked(){
    vertex_list.clear();
    initEdgeTable();
}

void MainWindow::initEdgeTable(){
    int i;
    for (i=0; i<maxHt; i++){
        EdgeTable[i].countEdgeBucket = 0;
    }
    ActiveEdgeTuple.countEdgeBucket = 0;
}


void removeEdgeByYmax(EdgeTableTuple *Tup,int yy){
    int i,j;
    for (i=0; i< Tup->countEdgeBucket; i++){
        if (Tup->buckets[i].ymax == yy){
            for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ ){
                Tup->buckets[j].ymax =Tup->buckets[j+1].ymax;
                Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin;
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse;
            }
            Tup->countEdgeBucket--;
            i--;
        }
    }
}

void updateXBySlopeInv(EdgeTableTuple *Tup){
    int i;
    for (i=0; i<Tup->countEdgeBucket; i++){
        (Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse;
    }
}

void MainWindow::on_scanLineFill_clicked(){
    int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;
    for (i=0; i<maxHt; i++){
        for (j=1; j<EdgeTable[i].countEdgeBucket-1; j++){
            std::vector<std::pair<int, int> > vertex_list;
            storeEdgeInTuple(&ActiveEdgeTuple,EdgeTable[i].buckets[j].ymax,EdgeTable[i].buckets[j].xofymin,
                             EdgeTable[i].buckets[j].slopeinverse);
            }
            removeEdgeByYmax(&ActiveEdgeTuple, i);
            insertionSort(&ActiveEdgeTuple);
            j = 0;
    //        FillFlag = 0;
            coordCount = 0;
            x1 = 0;
            x2 = 0;
            ymax1 = 0;
            ymax2 = 0;
            while (j<ActiveEdgeTuple.countEdgeBucket){
                if (coordCount%2==0){
                    x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin);
                    ymax1 = ActiveEdgeTuple.buckets[j].ymax;
                    if (x1==x2){
                        if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))){
                            x2 = x1;
                            ymax2 = ymax1;
                        }else{
                            coordCount++;
                        }
                    }else{
                        coordCount++;
                    }
                }else{
                    x2 = (int)ActiveEdgeTuple.buckets[j].xofymin;
                    ymax2 = ActiveEdgeTuple.buckets[j].ymax;
                    FillFlag = 0;
                    if (x1==x2){
                        if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))){
                            x1 = x2;
                            ymax1 = ymax2;
                        }else{
                            coordCount++;
                            FillFlag = 1;
                        }
                    }else{
                        coordCount++;
                        FillFlag = 1;
                    }
                if(FillFlag){
                    p1.setX(x1);p1.setY(i);
                    p2.setX(x2);p2.setY(i);
//                    drawDDALine(255, 0, 0);
                    on_bresenhamLine_clicked();
                    delay(69);
                }
            }
            j++;
        }
        updateXBySlopeInv(&ActiveEdgeTuple);
    }
    vertex_list.clear();
    initEdgeTable();
}



void MainWindow::boundaryfillUtility4point (int x, int y, QRgb edgecolor, int r, int g, int b) {
    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
    if(img.pixel(x,y) == edgecolor || img.pixel(x,y) == qRgb(r,g,b)) return;
    point(x,y,r,g,b);
    boundaryfillUtility4point(x - gs, y, edgecolor,r,g,b);
    boundaryfillUtility4point(x + gs, y, edgecolor,r,g,b);
    boundaryfillUtility4point(x, y - gs, edgecolor,r,g,b);
    boundaryfillUtility4point(x, y + gs, edgecolor,r,g,b);
}

void MainWindow::boundaryfillUtility8point (int x, int y, QRgb edgecolor, int r, int g, int b) {
    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
    if(img.pixel(x,y) == edgecolor || img.pixel(x,y) == qRgb(r,g,b)) return;
    point(x,y,r,g,b);
    boundaryfillUtility8point(x - gs, y, edgecolor,r,g,b);
    boundaryfillUtility8point(x + gs, y, edgecolor,r,g,b);
    boundaryfillUtility8point(x, y - gs, edgecolor,r,g,b);
    boundaryfillUtility8point(x, y + gs, edgecolor,r,g,b);

    boundaryfillUtility8point(x - gs, y + gs, edgecolor,r,g,b);
    boundaryfillUtility8point(x + gs, y - gs, edgecolor,r,g,b);
    boundaryfillUtility8point(x - gs, y - gs, edgecolor,r,g,b);
    boundaryfillUtility8point(x + gs, y + gs, edgecolor,r,g,b);
}

void MainWindow::on_boundaryFill_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
    int x = p1.x()/gs;
    int y = p1.y()/gs;
    x = x*gs + gs/2;
    y = y*gs + gs/2;
//    int x = sum_x / cnt;
//    int y = sum_y / cnt;
    point(x,y,0,0,0);

    if (ui->fill_selector->currentText() == "4 point fill") {
        boundaryfillUtility4point(x, y, qRgb (255, 255, 0), 255, 255, 255);
    }
    if (ui->fill_selector->currentText() == "8 point fill") {
        boundaryfillUtility8point(x, y, qRgb(255, 255, 0), 100, 100, 0);
    }
    sum_x = 0;
    sum_y = 0;
    cnt = 0;
}


//void MainWindow::on_fill_selector_activated(int index)
//{

//}

void MainWindow::floodfillUtility4point (int x, int y, int r, int g, int b) {
    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
        if(img.pixel(x,y) == qRgb(r,g,b)) return;
        point(x,y,r,g,b);
        floodfillUtility4point(x - gs, y, r,g,b);
        floodfillUtility4point(x + gs, y, r,g,b);
        floodfillUtility4point(x, y - gs, r,g,b);
        floodfillUtility4point(x, y + gs, r,g,b);
}

void MainWindow::floodfillUtility8point (int x, int y, int r, int g, int b) {
    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
        if(img.pixel(x,y) == qRgb(r,g,b)) return;
        point(x,y,r,g,b);
        delay(50);
        floodfillUtility8point(x - gs, y, r,g,b);
        floodfillUtility8point(x + gs, y, r,g,b);
        floodfillUtility8point(x, y - gs, r,g,b);
        floodfillUtility8point(x, y + gs, r,g,b);
        floodfillUtility8point(x - gs, y + gs, r,g,b);
        floodfillUtility8point(x + gs, y - gs, r,g,b);
        floodfillUtility8point(x - gs, y - gs, r,g,b);
        floodfillUtility8point(x + gs, y + gs, r,g,b);
}

void MainWindow::on_floodfill_clicked()
{
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        int x = p1.x()/gs;
        int y = p1.y()/gs;
        x = x*gs + gs/2;
        y = y*gs + gs/2;
        point(x,y,0,0,0);

        int r = 255, g = 255, b = 0;
        if (ui->fill_selector->currentText() == "4 point fill"){

           floodfillUtility4point(x,y,r,g,b);
       }
       else if (ui->fill_selector->currentText() == "8 point fill") {
            floodfillUtility8point(x, y, r, g, b);
       }
}

