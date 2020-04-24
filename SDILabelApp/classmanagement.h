#ifndef CLASSMANAGEMENT_H
#define CLASSMANAGEMENT_H

#include <QDialog>
#include "mainwindow.h"
#include "classfile.h"
#include "linkedList.h"

QT_BEGIN_NAMESPACE
namespace Ui { class classManagement; }
QT_END_NAMESPACE
///This class handles the dialog for managing classes
///
///handles the dialog created when you select the manage classes button on the home screen. Allows for the adding and removing of class names to the class file loaded
class classManagement : public QDialog
{
    Q_OBJECT

public:
    ///Initialises the classManagement GUI but buidling the UI elements
    explicit classManagement(QWidget *parent = nullptr);
    ~classManagement();
     void loadClassList();

private slots:
     ///Gets the name of the item in the class list selected and sets it as the text of the selected class box
     ///@param *item is a reference to the QListWidgetItem that was double clicked
    void on_classList_itemDoubleClicked(QListWidgetItem *item);

    ///adds the chosen class name to the class file loaded
    ///
    ///adds the chosen class name to the class file by calling the addClass() function in classFile
    void on_addButton_clicked();

    ///removes the chosen class name from the class fiel loaded
    ///
    ///removes the chosen class name from the class file by calling the removeClass() function in classFile
    void on_removeButton_clicked();

    ///closes the class management dialog
    ///
    ///when closes the program updates the class list and file path box
    void on_okButton_clicked();

private:
    Ui::classManagement *ui;



};

#endif // CLASSMANAGEMENT_H
