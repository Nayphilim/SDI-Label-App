/********************************************************************************
** Form generated from reading UI file 'classmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSMANAGEMENT_H
#define UI_CLASSMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_classManagement
{
public:
    QGridLayout *gridLayout_5;
    QListWidget *classList;
    QDialogButtonBox *buttonBox;
    QLineEdit *selectedClass;

    void setupUi(QDialog *classManagement)
    {
        if (classManagement->objectName().isEmpty())
            classManagement->setObjectName(QString::fromUtf8("classManagement"));
        classManagement->resize(400, 300);
        gridLayout_5 = new QGridLayout(classManagement);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        classList = new QListWidget(classManagement);
        classList->setObjectName(QString::fromUtf8("classList"));

        gridLayout_5->addWidget(classList, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(classManagement);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_5->addWidget(buttonBox, 1, 0, 1, 1);

        selectedClass = new QLineEdit(classManagement);
        selectedClass->setObjectName(QString::fromUtf8("selectedClass"));

        gridLayout_5->addWidget(selectedClass, 0, 1, 1, 1);


        retranslateUi(classManagement);
        QObject::connect(buttonBox, SIGNAL(accepted()), classManagement, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), classManagement, SLOT(reject()));

        QMetaObject::connectSlotsByName(classManagement);
    } // setupUi

    void retranslateUi(QDialog *classManagement)
    {
        classManagement->setWindowTitle(QCoreApplication::translate("classManagement", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class classManagement: public Ui_classManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSMANAGEMENT_H
