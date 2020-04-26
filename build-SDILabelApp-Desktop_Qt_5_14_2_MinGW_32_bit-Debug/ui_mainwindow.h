/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_8;
    QGroupBox *leftMenuGroupBox;
    QGridLayout *gridLayout_6;
    QGroupBox *zoomGroupBox;
    QGridLayout *gridLayout;
    QSlider *zoomSlider;
    QGroupBox *toolGroupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *imageView;
    QGraphicsView *graphicsView;
    QGroupBox *rightMenuGroupBox;
    QGridLayout *gridLayout_5;
    QGroupBox *annotationsGroupBox;
    QGridLayout *gridLayout_7;
    QLabel *annotationFileNameheader;
    QLineEdit *annotationFilePathBox;
    QPushButton *annotationFileExplorerButton;
    QPushButton *annotationSaveButton;
    QGroupBox *classesGroupBox;
    QGridLayout *gridLayout_4;
    QLineEdit *classesFilePathBox;
    QPushButton *newClassListButton;
    QPushButton *classesFileExplorerButton;
    QPushButton *manageClassesButton;
    QComboBox *classFileSortBox;
    QListWidget *classesFileList;
    QGroupBox *imagesGroupBox;
    QGridLayout *gridLayout_3;
    QLineEdit *ImagesFilePathBox;
    QPushButton *ImagesFileExplorerButton;
    QListWidget *ImagesFileList;
    QComboBox *imageFileListSortBox;
    QGroupBox *bottomMenuGroupBox;
    QGridLayout *gridLayout_9;
    QLabel *autoSaveLabel;
    QMenuBar *menubar;
    QMenu *menuSDI_Label_App;
    QMenu *menuLoad;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_8 = new QGridLayout(centralwidget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        leftMenuGroupBox = new QGroupBox(centralwidget);
        leftMenuGroupBox->setObjectName(QString::fromUtf8("leftMenuGroupBox"));
        leftMenuGroupBox->setAutoFillBackground(true);
        gridLayout_6 = new QGridLayout(leftMenuGroupBox);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        zoomGroupBox = new QGroupBox(leftMenuGroupBox);
        zoomGroupBox->setObjectName(QString::fromUtf8("zoomGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(zoomGroupBox->sizePolicy().hasHeightForWidth());
        zoomGroupBox->setSizePolicy(sizePolicy);
        zoomGroupBox->setMinimumSize(QSize(0, 300));
        gridLayout = new QGridLayout(zoomGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        zoomSlider = new QSlider(zoomGroupBox);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(zoomSlider, 0, 0, 1, 1);


        gridLayout_6->addWidget(zoomGroupBox, 1, 0, 1, 1);

        toolGroupBox = new QGroupBox(leftMenuGroupBox);
        toolGroupBox->setObjectName(QString::fromUtf8("toolGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolGroupBox->sizePolicy().hasHeightForWidth());
        toolGroupBox->setSizePolicy(sizePolicy1);
        toolGroupBox->setAutoFillBackground(true);
        toolGroupBox->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(toolGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_3 = new QPushButton(toolGroupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/images/triangleTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(100, 100));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(toolGroupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/images/rectangleTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(100, 100));

        verticalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(toolGroupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/images/trapeziumTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(100, 100));

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(toolGroupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/images/scaleTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);
        pushButton_6->setIconSize(QSize(100, 100));

        verticalLayout_2->addWidget(pushButton_6);


        gridLayout_6->addWidget(toolGroupBox, 0, 0, 1, 1);


        gridLayout_8->addWidget(leftMenuGroupBox, 0, 0, 2, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setAutoFillBackground(true);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1408, 980));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        imageView = new QLabel(scrollAreaWidgetContents_2);
        imageView->setObjectName(QString::fromUtf8("imageView"));

        gridLayout_2->addWidget(imageView, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(scrollAreaWidgetContents_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_8->addWidget(scrollArea, 0, 1, 1, 1);

        rightMenuGroupBox = new QGroupBox(centralwidget);
        rightMenuGroupBox->setObjectName(QString::fromUtf8("rightMenuGroupBox"));
        sizePolicy1.setHeightForWidth(rightMenuGroupBox->sizePolicy().hasHeightForWidth());
        rightMenuGroupBox->setSizePolicy(sizePolicy1);
        rightMenuGroupBox->setAutoFillBackground(true);
        gridLayout_5 = new QGridLayout(rightMenuGroupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        annotationsGroupBox = new QGroupBox(rightMenuGroupBox);
        annotationsGroupBox->setObjectName(QString::fromUtf8("annotationsGroupBox"));
        gridLayout_7 = new QGridLayout(annotationsGroupBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        annotationFileNameheader = new QLabel(annotationsGroupBox);
        annotationFileNameheader->setObjectName(QString::fromUtf8("annotationFileNameheader"));

        gridLayout_7->addWidget(annotationFileNameheader, 0, 0, 1, 1);

        annotationFilePathBox = new QLineEdit(annotationsGroupBox);
        annotationFilePathBox->setObjectName(QString::fromUtf8("annotationFilePathBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(annotationFilePathBox->sizePolicy().hasHeightForWidth());
        annotationFilePathBox->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(annotationFilePathBox, 1, 0, 1, 1);

        annotationFileExplorerButton = new QPushButton(annotationsGroupBox);
        annotationFileExplorerButton->setObjectName(QString::fromUtf8("annotationFileExplorerButton"));
        sizePolicy.setHeightForWidth(annotationFileExplorerButton->sizePolicy().hasHeightForWidth());
        annotationFileExplorerButton->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(annotationFileExplorerButton, 1, 1, 1, 1);

        annotationSaveButton = new QPushButton(annotationsGroupBox);
        annotationSaveButton->setObjectName(QString::fromUtf8("annotationSaveButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(annotationSaveButton->sizePolicy().hasHeightForWidth());
        annotationSaveButton->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(annotationSaveButton, 2, 0, 1, 1, Qt::AlignHCenter);


        gridLayout_5->addWidget(annotationsGroupBox, 2, 0, 1, 1);

        classesGroupBox = new QGroupBox(rightMenuGroupBox);
        classesGroupBox->setObjectName(QString::fromUtf8("classesGroupBox"));
        gridLayout_4 = new QGridLayout(classesGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        classesFilePathBox = new QLineEdit(classesGroupBox);
        classesFilePathBox->setObjectName(QString::fromUtf8("classesFilePathBox"));

        gridLayout_4->addWidget(classesFilePathBox, 0, 0, 1, 1);

        newClassListButton = new QPushButton(classesGroupBox);
        newClassListButton->setObjectName(QString::fromUtf8("newClassListButton"));

        gridLayout_4->addWidget(newClassListButton, 2, 0, 1, 1);

        classesFileExplorerButton = new QPushButton(classesGroupBox);
        classesFileExplorerButton->setObjectName(QString::fromUtf8("classesFileExplorerButton"));

        gridLayout_4->addWidget(classesFileExplorerButton, 0, 1, 1, 1);

        manageClassesButton = new QPushButton(classesGroupBox);
        manageClassesButton->setObjectName(QString::fromUtf8("manageClassesButton"));

        gridLayout_4->addWidget(manageClassesButton, 2, 1, 1, 1);

        classFileSortBox = new QComboBox(classesGroupBox);
        classFileSortBox->addItem(QString());
        classFileSortBox->addItem(QString());
        classFileSortBox->setObjectName(QString::fromUtf8("classFileSortBox"));

        gridLayout_4->addWidget(classFileSortBox, 0, 2, 1, 1);

        classesFileList = new QListWidget(classesGroupBox);
        classesFileList->setObjectName(QString::fromUtf8("classesFileList"));
        classesFileList->setSortingEnabled(false);

        gridLayout_4->addWidget(classesFileList, 1, 0, 1, 3);


        gridLayout_5->addWidget(classesGroupBox, 1, 0, 1, 1);

        imagesGroupBox = new QGroupBox(rightMenuGroupBox);
        imagesGroupBox->setObjectName(QString::fromUtf8("imagesGroupBox"));
        imagesGroupBox->setAutoFillBackground(true);
        gridLayout_3 = new QGridLayout(imagesGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ImagesFilePathBox = new QLineEdit(imagesGroupBox);
        ImagesFilePathBox->setObjectName(QString::fromUtf8("ImagesFilePathBox"));

        gridLayout_3->addWidget(ImagesFilePathBox, 0, 0, 1, 1);

        ImagesFileExplorerButton = new QPushButton(imagesGroupBox);
        ImagesFileExplorerButton->setObjectName(QString::fromUtf8("ImagesFileExplorerButton"));

        gridLayout_3->addWidget(ImagesFileExplorerButton, 0, 2, 1, 1);

        ImagesFileList = new QListWidget(imagesGroupBox);
        ImagesFileList->setObjectName(QString::fromUtf8("ImagesFileList"));
        ImagesFileList->setSortingEnabled(false);

        gridLayout_3->addWidget(ImagesFileList, 2, 0, 1, 4);

        imageFileListSortBox = new QComboBox(imagesGroupBox);
        imageFileListSortBox->addItem(QString());
        imageFileListSortBox->addItem(QString());
        imageFileListSortBox->addItem(QString());
        imageFileListSortBox->addItem(QString());
        imageFileListSortBox->setObjectName(QString::fromUtf8("imageFileListSortBox"));
        imageFileListSortBox->setEnabled(true);

        gridLayout_3->addWidget(imageFileListSortBox, 0, 3, 1, 1);


        gridLayout_5->addWidget(imagesGroupBox, 0, 0, 1, 1);


        gridLayout_8->addWidget(rightMenuGroupBox, 0, 2, 2, 1);

        bottomMenuGroupBox = new QGroupBox(centralwidget);
        bottomMenuGroupBox->setObjectName(QString::fromUtf8("bottomMenuGroupBox"));
        bottomMenuGroupBox->setAutoFillBackground(true);
        gridLayout_9 = new QGridLayout(bottomMenuGroupBox);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        autoSaveLabel = new QLabel(bottomMenuGroupBox);
        autoSaveLabel->setObjectName(QString::fromUtf8("autoSaveLabel"));

        gridLayout_9->addWidget(autoSaveLabel, 0, 0, 1, 1);


        gridLayout_8->addWidget(bottomMenuGroupBox, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        menuSDI_Label_App = new QMenu(menubar);
        menuSDI_Label_App->setObjectName(QString::fromUtf8("menuSDI_Label_App"));
        menuLoad = new QMenu(menubar);
        menuLoad->setObjectName(QString::fromUtf8("menuLoad"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSDI_Label_App->menuAction());
        menubar->addAction(menuLoad->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(ImagesFileExplorerButton, SIGNAL(clicked()), ImagesFilePathBox, SLOT(copy()));
        QObject::connect(ImagesFilePathBox, SIGNAL(textChanged(QString)), ImagesFileList, SLOT(update()));
        QObject::connect(classesFileExplorerButton, SIGNAL(clicked()), classesFilePathBox, SLOT(copy()));
        QObject::connect(classesFileExplorerButton, SIGNAL(clicked()), classesFileList, SLOT(update()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        leftMenuGroupBox->setTitle(QString());
        zoomGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        toolGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        pushButton_3->setText(QString());
        pushButton->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        imageView->setText(QString());
        rightMenuGroupBox->setTitle(QString());
        annotationsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Annotations", nullptr));
        annotationFileNameheader->setText(QCoreApplication::translate("MainWindow", "Annotation File Name", nullptr));
        annotationFileExplorerButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        annotationSaveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        classesGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Classes", nullptr));
        classesFilePathBox->setText(QString());
        newClassListButton->setText(QCoreApplication::translate("MainWindow", "Create New Class List", nullptr));
        classesFileExplorerButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        manageClassesButton->setText(QCoreApplication::translate("MainWindow", "Manage Classes", nullptr));
        classFileSortBox->setItemText(0, QCoreApplication::translate("MainWindow", "A-Z", nullptr));
        classFileSortBox->setItemText(1, QCoreApplication::translate("MainWindow", "Z-A", nullptr));

        imagesGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Images", nullptr));
        ImagesFilePathBox->setText(QString());
        ImagesFileExplorerButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        imageFileListSortBox->setItemText(0, QCoreApplication::translate("MainWindow", "A-Z", nullptr));
        imageFileListSortBox->setItemText(1, QCoreApplication::translate("MainWindow", "Z-A", nullptr));
        imageFileListSortBox->setItemText(2, QCoreApplication::translate("MainWindow", "Newest", nullptr));
        imageFileListSortBox->setItemText(3, QCoreApplication::translate("MainWindow", "Oldest", nullptr));

        bottomMenuGroupBox->setTitle(QString());
        autoSaveLabel->setText(QString());
        menuSDI_Label_App->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuLoad->setTitle(QCoreApplication::translate("MainWindow", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
