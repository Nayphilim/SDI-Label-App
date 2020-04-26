#include "classfile.h"

#include <iostream>

linkedList Classes;
QUrl CurrentClassFilePath;

classFile::classFile()
{

}

 linkedList classFile::readClassFile(QUrl filePath){
    linkedList classes;
    QFile file(filePath.toString());
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
          QString text = stream.readLine();
          //if class already exists in class list do not append
          if(!classes.contains(text) & !text.isEmpty()){
              classes.createNode(text);
          }

        }
        file.close();
    }
    CurrentClassFilePath = filePath;
    Classes = classes;
    return classes;

}

 linkedList classFile::getClasses(){
     return Classes;
 }

 void classFile::setClasses(linkedList classes){
     Classes = classes;
 }

 void classFile::clearClassList(){
     Classes.deleteList();
 }

 bool classFile::checkExisting(QString selectedClass){
     if(Classes.contains(selectedClass)){
         return true;
     }
     return false;

 }

 void classFile::addClass(QString selectedClass){
     //if class already exists in list of classes display error
     if(!(classFile::checkExisting(selectedClass))){
         QUrl currentClassFilePath = getCurrentClassFilePath();
         if(currentClassFilePath.isValid()){
             QFile file(currentClassFilePath.toString());
             if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
                 QTextStream stream(&file);
                 stream << "\n" << selectedClass;

             }
             file.close();
             Classes.createNode(selectedClass);
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

 void classFile::removeClass(int index){
     QUrl currentClassFilePath = getCurrentClassFilePath();
     if(currentClassFilePath.isValid()){
         Classes.deletePosition(index);
         QFile file(currentClassFilePath.toString());
         if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream stream(&file);
             for(int i = 0;i<Classes.size();i++){

                 stream << Classes.getDataAtPos(i) << endl;
             }

         }
         file.close();
     }

 }

 void classFile::setCurrentClassFilePath(QUrl classFilePath){
     CurrentClassFilePath = classFilePath;
 }


