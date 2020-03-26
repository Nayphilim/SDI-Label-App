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
    std::string imageFilePath = getImageFilePath();
    img = imread(imageFilePath + "/" + imageFileName);
    QImage imageDisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
    ui->imageView->setPixmap(QPixmap::fromImage(imageDisplay));
}


void MainWindow::on_ImagesFileExplorerButton_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    ui->ImagesFilePathBox->setText(filePath);
    updateImageFileList(filePath);



}

void MainWindow::updateImageFileList(QString filePath){
    QDir directory(filePath);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.JPG" << "*.PNG", QDir::Files);
    ui->ImagesFileList->clear();
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

void MainWindow::on_classesFileExplorerButton_clicked()
{
QString classFilePath = QFileDialog::getOpenFileName(this, "open a file", QDir::currentPath(), "*.txt");
 ui->classesFilePathBox->setText(classFilePath);
 classFile::clearClassList();
classFile::readClassFile(classFilePath);
 updateClassFileList();
}

void MainWindow::updateClassFileList(){
    ui->classesFileList->clear();
    ui->classesFileList->addItems(classFile::getClasses());
}

void MainWindow::on_manageClassesButton_clicked()
{
    classManagement classManagement(this);
    classManagement.setModal(true);
    int result = classManagement.exec();
    if(result==QDialog::Rejected){
        updateClassFileList();
    }
}



void MainWindow::on_newClassListButton_clicked()
{
    classListCreator classListCreator(this);
    classListCreator.setModal(true);
    int result = classListCreator.exec();



}
