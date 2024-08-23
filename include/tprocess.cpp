#include "tprocess.h"
using namespace tprocess;

void ProcessManager::RoundRobin()
{
}
uint16_t Process::getprocessID()
{
    return this->processID;
}

ProcessState Process::getstate()
{
    return this->state;
}

PCB::PCB(Process *p)
:ax(0), bx(0), cx(0), dx(0), sp(p->getstack().back()), bp(p->getheap().size()) /* si, di? */
{
}

