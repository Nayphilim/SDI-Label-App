#include "classlistcreator.h"
#include "ui_classlistcreator.h"

classListCreator::classListCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classListCreator)
{
    ui->setupUi(this);
}

classListCreator::~classListCreator()
{
    delete ui;
}

void classListCreator::on_classFileBrowseButton_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(0, ("Select a folder to save the class file to"), QDir::currentPath());
    ui->classFileLocationBox->setText(filePath);
}

void classListCreator::on_okButton_clicked()
{

    if(!(ui->classFileNameBox->text().isEmpty()) & !(ui->classFileLocationBox->text().isEmpty())){
        QString classFileName = ui->classFileNameBox->text() + ".txt";
        QString classFilePath = ui->classFileLocationBox->text() + "/" + classFileName;
        QMessageBox box;
        box.setText(classFilePath);
        box.exec();
        QFile classFile(classFilePath);
        classFile.open(QIODevice::WriteOnly);

    }
    else if(ui->classFileNameBox->text().isEmpty()){
        QMessageBox noFileNameAlert;
        noFileNameAlert.setText("Error: Please enter a file name for the class file you wish to save");
        noFileNameAlert.exec();
    }
    else if(ui->classFileLocationBox->text().isEmpty()){
        QMessageBox noFileLocationAlert;
        noFileLocationAlert.setText("Error: Please enter a file location for the class file you wish to save");
        noFileLocationAlert.exec();
    }
}
