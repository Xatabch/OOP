#include "delay.h"

#include <QTimer>
#include <QDebug>

void delay(size_t ms, std::function<void()> callback, QObject *parent)
{
    static QTimer *timer = nullptr;
    if (timer)
        delete timer;

    timer = new QTimer(parent);
    timer->setInterval(ms);

    QObject::connect(timer, &QTimer::timeout, callback);
    QObject::connect(timer, SIGNAL(timeout()), timer, SLOT(stop()));
    timer->start();
}
