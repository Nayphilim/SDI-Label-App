#include "classfile.h"

#include <iostream>
classFile::classFile()
{

}

 QStringList classFile::readClassFile(QUrl filePath){
    QStringList classes;
    QFile file(filePath.toEncoded());
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
          QString text = stream.readLine();
          classes.append(text);
        }
        file.close();
    }
    return classes;

}
