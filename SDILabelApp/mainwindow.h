#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"
#include "classfile.h"
#include "classmanagement.h"
#include "classlistcreator.h"
#include "linkedList.h"

#include<QTimer>
#include<QFileDialog>
#include<QString>
#include<QMessageBox>
#include<QDir>
#include<QPixmap>


#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "shape.h"
#include <json.hpp>
#include <QGraphicsView>
#include <QListWidget>
#include <QTimer>

using json = nlohmann::json;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
///This class handles all GUI components for the main window
///
///This class initialises the main window and handles all signals sent from the GUI. It also handles loading the image file through openCV.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///Initialises the main windows GUI by building the UI elements
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::string imageFileName;
    json annotation;



private:
public slots:

private slots:


    /// signals sent from the image file explorer button being clicked
    ///
    ///Opens the file explorer for the user to select a folder containing images
    void on_ImagesFileExplorerButton_clicked();

    ///Updates the list of image files in the UI with all image files contained in the folder the user has selected
    ///
    ///Uses the filepath provided by the users selection of folder and gets all png and jpg files and adds them to a list of strings which are then added to the list widget
    ///@param filePath A QString of the file path to the selected folder containing the image files that need to be loaded
    void updateImageFileList(QString filePath);

    ///Handles signals sent from the image file list items being double clicked
    ///
    ///Converts the name of the item from the image file list to a basic string and requests for the image to be displayed
    ///@param *item is a pointer to the item that the user has double clicked on in the image file list
    void on_ImagesFileList_itemDoubleClicked(QListWidgetItem *item);

    ///Displays the requested image from the image file list to the UI
    ///
    ///Loads the image based on the file path in the image file path box and the name of the image file in the image file list as a openCV mat and then converts it to a QImage to be displayed to the UI in a QLabel
    ///@param fileName String name of the image file that is to be displayed
    void DisplayImage(std::string fileName);

    ///Gets the file path of the image folder the user selected
    ///
    ///Gets the path based on what is entered into the image file box either by being manually typed by the user or automatically filled when selecting a folder through the file explorer
    std::string getImageFilePath();

    ///Loads the class file selected by the user
    ///
    ///Opens a file dialog for the user to select a *.names file on their pc and then clears the class list and loads the new one. It also sets the class list file path box to the full file path of the file loaded
    void on_classesFileExplorerButton_clicked();

    ///Updates thes class file list
    ///
    ///Updates the class list to show new/removed class names or to show an entirely new list of classes from a newly loaded file
    void updateClassFileList();

    ///opens the class manager dialog
    ///
    ///Updates the class list and file path box when the dialog is closed
    void on_manageClassesButton_clicked();

    ///opens the class list creator dialog
    ///
    ///loads the new class file when closed
    void on_newClassListButton_clicked();

    ///Detects when the user selects a new sort mode and applies that sort
    void on_imageFileListSortBox_currentIndexChanged(int index);

    ///sorts list of image files loaded alphabetically
    ///
    ///sorts the image files directly as they are being read in from the directory
    ///@param directory is the full directory of the image files being loaded
    void sortAlphabetically(QDir directory);

    ///sorts list of image files loaded reversed alphabetically
    ///
    ///sorts the image files directly as they are being read in from the directory
    ///@param directory is the full directory of the image files being loaded
    void sortReversedAlphabetically(QDir directory);

    ///sorts list of image files loaded by the newest file
    ///
    ///sorts the image files directly as they are being read in from the directory
    ///@param directory is the full directory of the image files being loaded
    void sortNewest(QDir directory);

    ///sorts list of image files loaded by the oldest file
    ///
    ///sorts the image files directly as they are being read in from the directory
    ///@param directory is the full directory of the image files being loaded
    void sortOldest(QDir directory);

    ///returns the full directory of the image files to be loaded
    ///
    ///returns the diretory displayed in the imageFileDirectory text box
    QDir getImageFileDirectory();

    ///Detects when the user selects a new sort mode and applies that sort
    ///
    ///Uses bubble sort to sort the class file linked list into order
    ///@param index the index of the option pressed by the user in the drop down menu
    void on_classFileSortBox_currentIndexChanged(int index);

    ///detects when push button to create a square is pressed
    void on_pushButton_clicked();

    ///reads given annotations file to load shapes for a chosen image
    void readJson();

    ///opens the file explorer for the user to select an annotation
    void on_annotationFileExplorerButton_clicked();

    ///saves the JSON object to file
    void on_annotationSaveButton_clicked();

    ///detects when push button to create a triangle is pressed
    void on_pushButton_3_clicked();

    ///detects when push button to create a trapezium is pressed
    void on_pushButton_4_clicked();

    ///detects when push button to scale a shape is pressed
    void on_pushButton_6_clicked();

    ///will save a JSON object to given file, if the file contains JSON, it will add to the struct
    void saveJson();

    void on_actionhelp_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Shape *shape;


protected:
    ///detects what key was pressed and performs an action based on it
    ///
    ///currently handles a delete key press which deletes the last selected shape
    void keyPressEvent(QKeyEvent*);
};


#endif // MAINWINDOW_H
