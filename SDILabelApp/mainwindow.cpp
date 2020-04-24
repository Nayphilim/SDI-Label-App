#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    showMaximized();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::DisplayImage(std::string imageFileName){
    scene = new QGraphicsScene(this);
    std::string imageFilePath = getImageFilePath();
    QString imagePath = QString::fromStdString(imageFilePath + "/" + imageFileName);
    QPixmap image(imagePath);
    scene->addPixmap(image);
    ui->graphicsView->setScene(scene);
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
    linkedList classes = classFile::getClasses();
    for(int i=0; i<classes.size();i++){
    ui->classesFileList->addItem(classes.getDataAtPos(i));
    }

    ui->classesFileList->setDragEnabled(true);
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
    linkedList classes = classFile::getClasses();
    switch(index){
    case 0:
        ui->classesFileList->clear();
        for(int i=0;i<classes.size()-1;i++){
            for(int j=0;j<classes.size()-i-1;j++){
                if(classes.getDataAtPos(j) > classes.getDataAtPos(j+1)){
                    classes.swap(j,j+1);
                }
        }
        }
        for(int i=0; i<classes.size();i++){
        ui->classesFileList->addItem(classes.getDataAtPos(i));
        }
        break;

    case 1:
        ui->classesFileList->clear();
        for(int i=0;i<classes.size()-1;i++){
            for(int j=0;j<classes.size()-i-1;j++){
                if(classes.getDataAtPos(j) < classes.getDataAtPos(j+1)){
                    classes.swap(j,j+1);
                }
        }
        }
        for(int i=0; i<classes.size();i++){
        ui->classesFileList->addItem(classes.getDataAtPos(i));
        }
        break;
}
}

void MainWindow::on_pushButton_clicked()
{
    shape = new Shape(1);
    scene->addItem(shape);
    i = 1;
    
}
void MainWindow::on_pushButton_3_clicked()
{
    shape = new Shape(3);
    scene->addItem(shape);
    i = 1;
}

void MainWindow::on_pushButton_4_clicked()
{
    shape = new Shape(2);
    scene->addItem(shape);
    i = 1;
}



void MainWindow::on_pushButton_6_clicked()
{
    foreach(QGraphicsItem * item, scene->selectedItems())
    {
        if(i < 6)
        {
            i++;
        }
        else
        {
            i = 1;
        }
        item->setScale(i);
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete){
        foreach(QGraphicsItem * item, scene->selectedItems())
        {
            scene->removeItem(item);
            delete item;
        }
    }

    QMainWindow::keyPressEvent(event);
}




