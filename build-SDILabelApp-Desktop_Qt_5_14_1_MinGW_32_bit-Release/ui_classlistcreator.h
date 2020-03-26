/********************************************************************************
** Form generated from reading UI file 'classlistcreator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSLISTCREATOR_H
#define UI_CLASSLISTCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_classListCreator
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *classFileLocationBox;
    QPushButton *classFileBrowseButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *classFileNameBox;
    QPushButton *okButton;

    void setupUi(QDialog *classListCreator)
    {
        if (classListCreator->objectName().isEmpty())
            classListCreator->setObjectName(QString::fromUtf8("classListCreator"));
        classListCreator->resize(400, 186);
        gridLayout_2 = new QGridLayout(classListCreator);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(classListCreator);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        classFileLocationBox = new QLineEdit(groupBox_2);
        classFileLocationBox->setObjectName(QString::fromUtf8("classFileLocationBox"));

        horizontalLayout->addWidget(classFileLocationBox);

        classFileBrowseButton = new QPushButton(groupBox_2);
        classFileBrowseButton->setObjectName(QString::fromUtf8("classFileBrowseButton"));

        horizontalLayout->addWidget(classFileBrowseButton);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(classListCreator);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        classFileNameBox = new QLineEdit(groupBox);
        classFileNameBox->setObjectName(QString::fromUtf8("classFileNameBox"));

        verticalLayout_2->addWidget(classFileNameBox);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        okButton = new QPushButton(classListCreator);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        gridLayout_2->addWidget(okButton, 2, 0, 1, 1);


        retranslateUi(classListCreator);

        QMetaObject::connectSlotsByName(classListCreator);
    } // setupUi

    void retranslateUi(QDialog *classListCreator)
    {
        classListCreator->setWindowTitle(QCoreApplication::translate("classListCreator", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("classListCreator", "Location", nullptr));
        classFileBrowseButton->setText(QCoreApplication::translate("classListCreator", "Browse", nullptr));
        groupBox->setTitle(QCoreApplication::translate("classListCreator", "File Name", nullptr));
        okButton->setText(QCoreApplication::translate("classListCreator", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class classListCreator: public Ui_classListCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSLISTCREATOR_H
