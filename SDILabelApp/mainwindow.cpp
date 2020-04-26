#include "mainwindow.h"
#include <fstream>


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
    imageFileName = QImageFileName.toStdString();
    DisplayImage(imageFileName);
    try {
        readJson();
    } catch (...) {
    }

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
    ui->classesFilePathBox->setText(classFile::getCurrentClassFilePath().toString());
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

//square button
void MainWindow::on_pushButton_clicked()
{
    shape = new Shape("square");
    shape->setData(0,"square");
    scene->addItem(shape);
}
//triangle button
void MainWindow::on_pushButton_3_clicked()
{
    shape = new Shape("triangle");
    shape->setData(0,"triangle");
    scene->addItem(shape);
}
//trapezium button
void MainWindow::on_pushButton_4_clicked()
{
    shape = new Shape("trapezium");
    shape->setData(0,"trapezium");
    scene->addItem(shape);
}


//scale button
void MainWindow::on_pushButton_6_clicked()
{
    foreach(QGraphicsItem * item, scene->selectedItems())
    {
        int i = item->scale();
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

void MainWindow::on_annotationSaveButton_clicked(){
    saveJson();
}

void MainWindow::saveJson()
{
    json j;
    try {
        j = annotation;
    } catch (...) {

    }

    QString qAnnotationFilePath = ui->annotationFilePathBox->text();

    j["images"][imageFileName]["numOfshapes"] = scene->items().count();
    std::vector<json> shapes;
    json shape;
    foreach(QGraphicsItem * item, scene->items())
    {
        shape["type"] = "";
        if (item->data(0).toString().toStdString() != ""){
            shape["type"] = item->data(0).toString().toStdString();
        }

        int xOffset = item->pos().x();
        int yOffset = item->pos().y();

        shape["scale"] = item->scale();
        if (shape["type"] == "square"){
            shape["point_1"] = {10+xOffset,10+yOffset};
            shape["point_2"] = {100+xOffset,10+yOffset};
            shape["point_3"] = {100+xOffset,100+yOffset};
            shape["point_4"] = {10+xOffset,100+yOffset};
            shapes.push_back(shape);
        }
        else if (shape["type"] == "trapezium"){
            shape["point_1"] = {10+xOffset,60+yOffset};
            shape["point_2"] = {80+xOffset,10+yOffset};
            shape["point_3"] = {170+xOffset,10+yOffset};
            shape["point_4"] = {190+xOffset,60+yOffset};
            shapes.push_back(shape);
        }
        else if (shape["type"] == "triangle"){
            shape["point_1"] = {75+xOffset,25+yOffset};
            shape["point_2"] = {25+xOffset,125+yOffset};
            shape["point_3"] = {125+xOffset,125+yOffset};
            shapes.push_back(shape);
        }

    }
    j["images"][imageFileName]["shapes"] = shapes;
    j["numOfImages"] = j["images"].size();
    std::ofstream out;
    out.open (qAnnotationFilePath.toStdString());
    out << j;
    out.close();
}

void MainWindow::readJson()
{
    std::ifstream myfile;
    QString qAnnotationFilePath = ui->annotationFilePathBox->text();
    myfile.open (qAnnotationFilePath.toStdString());
    myfile >> annotation;
    myfile.close();
    QVariant type;
    int len = annotation["images"][imageFileName]["numOfshapes"];
    for (int index = 0; index < len; index++) {
        type = QString::fromStdString(annotation["images"][imageFileName]["shapes"].at(index)["type"]);
        std::vector<std::vector<int>> points;
        int xOffset = annotation["images"][imageFileName]["shapes"].at(index)["point_1"].at(0);
        int yOffset = annotation["images"][imageFileName]["shapes"].at(index)["point_1"].at(1);
        if (annotation["images"][imageFileName]["shapes"].at(index)["type"] == "square"){
            xOffset -= 10;
            yOffset -= 10;
        }
        else if (annotation["images"][imageFileName]["shapes"].at(index)["type"] == "trapezium"){
            xOffset -= 10;
            yOffset -= 60;
        }
        else if (annotation["images"][imageFileName]["shapes"].at(index)["type"] == "triangle"){
            xOffset -= 75;
            yOffset -= 25;
        }
        shape = new Shape(annotation["images"][imageFileName]["shapes"].at(index)["type"]);
        shape->setData(0,type);
        shape->setPos(xOffset,yOffset);
        shape->setScale(annotation["images"][imageFileName]["shapes"].at(index)["scale"]);
        scene->addItem(shape);
    }
}

void MainWindow::on_annotationFileExplorerButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(0, ("Select Annotation File"), QDir::currentPath());
    ui->annotationFilePathBox->setText(filePath);
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




