#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage ImageDisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application
public slots:
    void DisplayImage();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
