#include "classmanagement.h"
#include "ui_classmanagement.h"


classManagement::classManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classManagement)
{
    ui->setupUi(this);
    loadClassList();
}

classManagement::~classManagement()
{
    delete ui;
}

void classManagement::loadClassList(){
    ui->classList->clear();
    QStringList classes = classFile::getClasses();
    ui->classList->addItems(classes);
}

void classManagement::on_classList_itemDoubleClicked(QListWidgetItem *item)
{
    QListWidgetItem classItem = *item;
    QString className = classItem.text();
    ui->selectedClass->setText(className);
}

void classManagement::on_addButton_clicked()
{
    QString selectedClass = ui->selectedClass->text();
    //if text box is empty display error
    if(!(ui->selectedClass->text().isEmpty())){
        classFile::addClass(selectedClass);
        loadClassList();
    }
    else{
        QMessageBox blankClassAlert;
        blankClassAlert.setText("Error: Please select a new class to be added to your class list");
        blankClassAlert.exec();
    }
}


void classManagement::on_removeButton_clicked()
{
    QString selectedClass = ui->selectedClass->text();
    //if text box is empty display error
    if(!(ui->selectedClass->text().isEmpty())){
        classFile::removeClass(selectedClass);
        loadClassList();
    }
    else{
        QMessageBox blankClassAlert;
        blankClassAlert.setText("Error: Please select a class to be removed from your class list");
        blankClassAlert.exec();
    }

}

void classManagement::on_okButton_clicked()
{
   this->close();
}
