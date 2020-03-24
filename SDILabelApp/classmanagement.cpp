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
    QStringList classes = classFile::getClasses();
    ui->classList->addItems(classes);
}
