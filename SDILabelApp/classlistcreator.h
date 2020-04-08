#ifndef CLASSLISTCREATOR_H
#define CLASSLISTCREATOR_H

#include "mainwindow.h"
#include "classfile.h"

#include <QDialog>

namespace Ui {
///This class is for the new class creation dialog
///
///This class handles the dialog when selecting the create new class list button. It takes the name and file path given and creates a new class file with the name at the location specified
class classListCreator;
}

class classListCreator : public QDialog
{
    Q_OBJECT

public:
    ///initialises the classListCreator GUI by building the UI elements
    explicit classListCreator(QWidget *parent = nullptr);
    ~classListCreator();

private slots:
    ///Opens a file dialog to select a folder directory for the class file to be created.
    ///
    ///Opens the file dialog for the user to select a directory which is then set as the text for the file path box. Function is called when the file browse button is clicked
    void on_classFileBrowseButton_clicked();
    ///Creates the class file with the name and location chosen
    ///
    ///Creates the class file using the name from the name box and location from the file path box as parameters.
    void on_okButton_clicked();

private:
    Ui::classListCreator *ui;
};

#endif // CLASSLISTCREATOR_H
