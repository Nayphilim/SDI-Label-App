#include "mainwindow.h"

using namespace cv;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    showMaximized();
    //DisplayImage();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayImage(std::string imageFileName){
    Mat img;
    //img = imread("D:/Nayphilim/Documents/GitHub/SDI-Label-App/SDILabelApp/res/test.png");
    std::string imageFilePath = getImageFilePath();
    img = imread(imageFilePath + "/" + imageFileName);
    QImage imageDisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
    ui->imageView->setPixmap(QPixmap::fromImage(imageDisplay));
}


void MainWindow::on_ImagesFileExplorerButton_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    //QMessageBox::information(this, "", filePath);
    ui->ImagesFilePathBox->setText(filePath);
    updateImageFileList(filePath);



}

void MainWindow::updateImageFileList(QString filePath){
    QDir directory(filePath);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.JPG" << "*.PNG", QDir::Files);
    ui->ImagesFileList->addItems(images);
}

void MainWindow::on_ImagesFileList_itemDoubleClicked(QListWidgetItem *item)
{
    QListWidgetItem qImageFileItem = *item;
    QString QImageFileName = qImageFileItem.text();
    std::string imageFileName = QImageFileName.toStdString();
    DisplayImage(imageFileName);
}

std::string MainWindow::getImageFilePath(){
    QString qImageFilePath = ui->ImagesFilePathBox->text();
    std::string imageFilePath = qImageFilePath.toStdString();
    return imageFilePath;
}
