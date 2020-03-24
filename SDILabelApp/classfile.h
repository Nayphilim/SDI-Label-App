#ifndef CLASSFILE_H
#define CLASSFILE_H

#include "mainwindow.h"

#include <QTextStream>


class classFile
{
public:
    classFile();
    static QStringList readClassFile(QUrl filePath);

private:

};

#endif // CLASSFILE_H
