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

private slots:

private:
    Ui::classManagement *ui;

    void loadClassList();

};

#endif // CLASSMANAGEMENT_H
