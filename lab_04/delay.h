#ifndef DELAY_H
#define DELAY_H

#include <cstddef>
#include <functional>

#include <QObject>

void delay(size_t ms,  std::function<void()>, QObject *parent = nullptr);
void delay(size_t ms);


#endif // DELAY_H
