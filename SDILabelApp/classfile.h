#ifndef CLASSFILE_H
#define CLASSFILE_H

#include "mainwindow.h"
#include "linkedList.h"

#include <QTextStream>
#include <algorithm>

class linkedList;

///This class manages all class file functionaility
///
///This class contains all functions attributing to the creation, loading and managing of class files. It also holds the current loaded class list and the full file path of the class file in use
class classFile
{
public:
    classFile();
    ///returns the list of classes in loaded class file
    static linkedList getClasses();
    ///reads the class file selected
    ///
    ///reads the class file selected by the user by reading each line individually and appending it to a QStringList
    ///@param filePath is the full path to the selected class file that is being read
    static linkedList readClassFile(QUrl filePath);
    ///sets the list of classes
    ///
    ///sets the QStringList of classes that will be displayed in the class list widget and will be saved to the file
    ///@param classes is the new list of classes to be set
    static void setClasses(linkedList classes);
    ///clears the list of classes
    ///
    /// clears the current QStringList of classes to be rewritten
    static void clearClassList();
    ///checks if a class already exists inside a class file
    ///
    ///checks for duplicate class names that are in the loaded class file. Using a combination of QRegularExpression and the QStringList function indexOf will return -1 if it does not contain the string given as a parameter
    ///@param selectedClass is the class name that is being compared for duplicates
    static bool checkExisting(QString selectedClass);
    ///adds a new class to the class file in use
    ///
    ///adds a new class to the class file loaded as well as appending it to the class list
    ///@param selectedClass is the class name to be added
    static void addClass(QString selectedClass);
    ///returns the full file path of the class file
    ///
    ///returns the full file path of the class file that is currently in use
    static QUrl getCurrentClassFilePath();
    ///removes a class from the class file in use
    ///
    ///removes all instances of a class name entered from the class QStringList and then rewrites the the file with the new QStringList
    ///@param selectedClass is the class name selected to be removed
    static void removeClass(int index);
    ///sets the full file path of the class file to be loaded
    ///@param classFilePath is the full file path of the class file to be loaded
    static void setCurrentClassFilePath(QUrl classFilePath);

    static void sortAlphabetically();

    static bool AlphabeticComparison(QString a, QString b);

    static void sortReversedAlphabetically();

    static bool ReversedAlphabeticComparison(QString a, QString b);


private:



};

#endif // CLASSFILE_H
