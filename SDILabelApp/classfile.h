#ifndef CLASSFILE_H
#define CLASSFILE_H

#include "mainwindow.h"

#include <QTextStream>


class classFile
{
public:
    classFile();
    static QStringList getClasses();
    static QStringList readClassFile(QUrl filePath);
    static void setClasses(QStringList classes);
    static void clearClassList();
    static bool checkExisting(QString selectedClass);
    static void addClass(QString selectedClass);
    static QUrl getCurrentClassFilePath();
    static void removeClass(QString selectedClass);
    static void setCurrentClassFilePath(QUrl classFilePath);


private:



};

#endif // CLASSFILE_H
