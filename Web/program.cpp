#include "program.h"

void Program::sendAcrossLocal(int compId, Program *message)
{
    emit sendToLocal(compId, message);
}
