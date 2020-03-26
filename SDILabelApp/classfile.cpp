#include "classfile.h"

#include <iostream>

QStringList Classes;
QUrl CurrentClassFilePath;

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
          //if class already exists in class list do not append
          if((classes.indexOf(QRegularExpression(text)) == -1) & text !=""){
              classes.append(text);
          }

        }
        file.close();
    }
    CurrentClassFilePath = filePath;
    Classes = classes;
    return classes;

}

 QStringList classFile::getClasses(){
     return Classes;
 }

 void classFile::setClasses(QStringList classes){
     Classes = classes;
 }

 void classFile::clearClassList(){
     Classes.clear();
 }

 bool classFile::checkExisting(QString selectedClass){
     if(Classes.indexOf(QRegularExpression(selectedClass)) == -1){
         return false;
     }
     return true;

 }

 void classFile::addClass(QString selectedClass){
     //if class already exists in list of classes display error
     if(!(classFile::checkExisting(selectedClass))){
         QUrl currentClassFilePath = getCurrentClassFilePath();
         if(currentClassFilePath.isValid()){
             QFile file(currentClassFilePath.toEncoded());
             if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
                 QTextStream stream(&file);
                 stream << "\n" << selectedClass;

             }
             file.close();
             Classes.append(selectedClass);
         }
     }
     else{
         QMessageBox existingClassAlert;
         existingClassAlert.setText("Error: Class already exists in class list");
         existingClassAlert.exec();
     }

 }

 QUrl classFile::getCurrentClassFilePath(){
     if(!CurrentClassFilePath.isValid()){
         QMessageBox noClassFileAlert;
         noClassFileAlert.setText("Error: Please load an existing class file or create a new one before trying to make changes");
         noClassFileAlert.exec();
     }
     return CurrentClassFilePath;
 }

 void classFile::removeClass(QString selectedClass){
     QUrl currentClassFilePath = getCurrentClassFilePath();
     if(currentClassFilePath.isValid()){
         Classes.removeAll(selectedClass);
         QFile file(currentClassFilePath.toEncoded());
         if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream stream(&file);
             for(const auto& i : Classes){
                 stream << i << endl;
             }

         }
         file.close();
     }

 }

 void classFile::setCurrentClassFilePath(QUrl classFilePath){
     CurrentClassFilePath = classFilePath;
 }
