#include "autosavetimer.h"
#include <QTimer>
autoSaveTimer::autoSaveTimer()
{
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(MyTimerSlot()));

    timer->start(60000);
}

void autoSaveTimer::MyTimerSlot(){
    MainWindow window;
    window.saveJson();
    window.showAutoSave();
}
