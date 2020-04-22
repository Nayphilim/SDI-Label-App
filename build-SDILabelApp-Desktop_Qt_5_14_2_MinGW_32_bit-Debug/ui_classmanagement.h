/********************************************************************************
** Form generated from reading UI file 'classmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSMANAGEMENT_H
#define UI_CLASSMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_classManagement
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *editingOptions;
    QVBoxLayout *verticalLayout;
    QLineEdit *selectedClass;
    QPushButton *addButton;
    QPushButton *removeButton;
    QListWidget *classList;
    QPushButton *okButton;

    void setupUi(QDialog *classManagement)
    {
        if (classManagement->objectName().isEmpty())
            classManagement->setObjectName(QString::fromUtf8("classManagement"));
        classManagement->resize(400, 300);
        gridLayout_5 = new QGridLayout(classManagement);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        editingOptions = new QGroupBox(classManagement);
        editingOptions->setObjectName(QString::fromUtf8("editingOptions"));
        verticalLayout = new QVBoxLayout(editingOptions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        selectedClass = new QLineEdit(editingOptions);
        selectedClass->setObjectName(QString::fromUtf8("selectedClass"));

        verticalLayout->addWidget(selectedClass);

        addButton = new QPushButton(editingOptions);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        removeButton = new QPushButton(editingOptions);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        verticalLayout->addWidget(removeButton);


        gridLayout_5->addWidget(editingOptions, 0, 3, 1, 2);

        classList = new QListWidget(classManagement);
        classList->setObjectName(QString::fromUtf8("classList"));
        classList->setMouseTracking(true);
        classList->setSortingEnabled(true);

        gridLayout_5->addWidget(classList, 0, 0, 1, 2);

        okButton = new QPushButton(classManagement);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        gridLayout_5->addWidget(okButton, 1, 1, 1, 1);


        retranslateUi(classManagement);
        QObject::connect(classList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), selectedClass, SLOT(update()));

        QMetaObject::connectSlotsByName(classManagement);
    } // setupUi

    void retranslateUi(QDialog *classManagement)
    {
        classManagement->setWindowTitle(QCoreApplication::translate("classManagement", "Dialog", nullptr));
        editingOptions->setTitle(QString());
        addButton->setText(QCoreApplication::translate("classManagement", "Add", nullptr));
        removeButton->setText(QCoreApplication::translate("classManagement", "Remove", nullptr));
        okButton->setText(QCoreApplication::translate("classManagement", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class classManagement: public Ui_classManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSMANAGEMENT_H
