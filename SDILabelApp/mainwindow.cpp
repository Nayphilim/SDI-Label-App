#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(DisplayImage()));
    Timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayImage(){
    Mat img;
    img = imread("D:/Nayphilim/Documents/GitHub/SDI-Label-App/SDILabelApp/res/test.png");
    QImage imageDisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
    ui->imageView->setPixmap(QPixmap::fromImage(imageDisplay));
}

