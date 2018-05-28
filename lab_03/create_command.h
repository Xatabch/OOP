#ifndef CREATE_COMMAND_H
#define CREATE_COMMAND_H

#include "create.h"

class CreateCommand
{
protected:
    CreateCommand(Transform*): ptrCreate(t) {}
    Create* ptrCreate;

public:
    virtual ~CreateCommand() {}
    virtual void execute() = 0;
};

#endif // CREATE_COMMAND_H
