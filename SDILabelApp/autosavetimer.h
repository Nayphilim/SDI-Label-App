#ifndef AUTOSAVETIMER_H
#define AUTOSAVETIMER_H

#include "mainwindow.h"

class autoSaveTimer : public QObject
{
public:
    autoSaveTimer();
    QTimer *timer;

private:
    void MyTimerSlot();
};

#endif // AUTOSAVETIMER_H
