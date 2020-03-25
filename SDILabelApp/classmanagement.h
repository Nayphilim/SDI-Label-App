#ifndef CLASSMANAGEMENT_H
#define CLASSMANAGEMENT_H

#include <QDialog>
#include "mainwindow.h"
#include "classfile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class classManagement; }
QT_END_NAMESPACE

class classManagement : public QDialog
{
    Q_OBJECT

public:
    explicit classManagement(QWidget *parent = nullptr);
    ~classManagement();
     void loadClassList();

private slots:

    void on_classList_itemDoubleClicked(QListWidgetItem *item);

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_okButton_clicked();

private:
    Ui::classManagement *ui;



};

#endif // CLASSMANAGEMENT_H
