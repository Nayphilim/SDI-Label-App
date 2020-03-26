#ifndef CLASSLISTCREATOR_H
#define CLASSLISTCREATOR_H

#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class classListCreator;
}

class classListCreator : public QDialog
{
    Q_OBJECT

public:
    explicit classListCreator(QWidget *parent = nullptr);
    ~classListCreator();

private slots:
    void on_classFileBrowseButton_clicked();

    void on_okButton_clicked();

private:
    Ui::classListCreator *ui;
};

#endif // CLASSLISTCREATOR_H
