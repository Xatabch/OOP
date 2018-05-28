#include "doors.h"

const int doors::DEL = 500;

doors::doors(QObject *parent):QObject(parent)
{
    this->state = close_state;
}


void doors::open()
{
    if(this->state != open_state)
    {
        std::cout << "Двери открываются..." << std::endl;
        this->state = open_state;
        delay(DEL);
        std::cout << "Двери открыты..." << std::endl;
        emit this->opening_doors();
    }
    else
        delay(DEL);

}


void doors::close()
{
    if(this->state != close_state)
    {
        std::cout << "Двери закрываются..." << std::endl;
        this->state = close_state;
        delay(DEL);
        std::cout << "Двери закрыты..." << std::endl;
        emit this->closing_doors();
    }
    else
        delay(DEL);
}
