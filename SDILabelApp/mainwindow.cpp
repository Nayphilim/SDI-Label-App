#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    showMaximized();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayImage(std::string imageFileName){
    std::string imageFilePath = getImageFilePath();
    QString imagePath = QString::fromStdString(imageFilePath + "/" + imageFileName);
    QPixmap image(imagePath);
    ui->imageView->setPixmap(image);
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
QString classFilePath = QFileDialog::getOpenFileName(this, "open a file", QDir::currentPath(), "*.names");
 ui->classesFilePathBox->setText(classFilePath);
 classFile::clearClassList();
classFile::readClassFile(classFilePath);
 updateClassFileList();
}

void MainWindow::updateClassFileList(){
    classFile::readClassFile(classFile::getCurrentClassFilePath());
    ui->classesFilePathBox->clear();
    ui->classesFileList->clear();
    ui->classesFilePathBox->setText(classFile::getCurrentClassFilePath().toEncoded());
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
    if(result==QDialog::Rejected){
        updateClassFileList();
    }

}

void MainWindow::on_imageFileListSortBox_currentIndexChanged(int index)
{
    //activate sort algorithm that is chosen
    QDir directory = getImageFileDirectory();
    switch(index){
    case 0:
        sortAlphabetically(directory);
        break;
    case 1:
        sortReversedAlphabetically(directory);
        break;
    case 2:
        sortNewest(directory);
        break;
    case 3:
        sortOldest(directory);
        break;

}
}

QDir MainWindow::getImageFileDirectory(){
    QDir directory(ui->ImagesFilePathBox->text());
    return directory;
}

void MainWindow::sortAlphabetically(QDir directory){
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.JPG" << "*.PNG", QDir::Files, QDir::Name);
    ui->ImagesFileList->clear();
    ui->ImagesFileList->addItems(images);
}

void MainWindow::sortReversedAlphabetically(QDir directory){
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.JPG" << "*.PNG", QDir::Files, QDir::Name | QDir::Reversed);
    ui->ImagesFileList->clear();
    ui->ImagesFileList->addItems(images);
}

void MainWindow::sortNewest(QDir directory){
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.JPG" << "*.PNG", QDir::Files, QDir::Time);
    ui->ImagesFileList->clear();
    ui->ImagesFileList->addItems(images);
}

void MainWindow::sortOldest(QDir directory){
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.JPG" << "*.PNG", QDir::Files, QDir::Time | QDir::Reversed);
    ui->ImagesFileList->clear();
    ui->ImagesFileList->addItems(images);
}

void MainWindow::on_classFileSortBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        classFile::sortAlphabetically();
        ui->classesFileList->clear();
        ui->classesFileList->addItems(classFile::getClasses());
        break;

    case 1:
        classFile::sortReversedAlphabetically();
        ui->classesFileList->clear();
        ui->classesFileList->addItems(classFile::getClasses());
        break;
}
}
