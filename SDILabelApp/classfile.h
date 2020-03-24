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
    void setClasses(QStringList classes);


private:



};

#endif // CLASSFILE_H
