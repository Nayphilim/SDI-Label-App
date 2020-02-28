#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include<QTimer>
#include<QFileDialog>
#include<QString>
#include<QMessageBox>
#include<QDir>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:


private slots:
    void on_ImagesFileExplorerButton_clicked();

    void updateImageFileList(QString);

    void on_ImagesFileList_itemDoubleClicked(QListWidgetItem *item);

    void DisplayImage(std::string);

    std::string getImageFilePath();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
