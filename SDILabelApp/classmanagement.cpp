#include "classmanagement.h"
#include "ui_classmanagement.h"

int selectedItemIndex;
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
    linkedList classes = classFile::getClasses();
    for(int i=0; i<classes.size();i++){
    ui->classList->addItem(classes.getDataAtPos(i));
    ui->classList->setCurrentRow(i+1);
    }
}

void classManagement::on_classList_itemDoubleClicked(QListWidgetItem *item)
{
    selectedItemIndex = ui->classList->currentRow();
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
        classFile::removeClass(selectedItemIndex);
        loadClassList();

}

void classManagement::on_okButton_clicked()
{
   this->close();
}
