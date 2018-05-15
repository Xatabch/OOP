#include "doors.h"

const int doors::del = 1000;

doors::doors(QObject *parent):QObject(parent)
{
    this->state = close_state;
}


void doors::open()
{
    std::cout << "Двери открываются..." << std::endl;
    this->state = open_state;
    std::cout << "Двери открыты..." << std::endl;
    emit this->opening_doors();

}


void doors::close()
{
    std::cout << "Двери закрываются..." << std::endl;
    this->state = close_state;
    std::cout << "Двери закрыты..." << std::endl;
    emit this->closing_doors();
}
