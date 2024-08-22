#pragma once
#include <cstdint>
#include <vector>
#include "toothless.h"

namespace tprocess
{
    class ProcessManager
    {
    private:
        Kernel kernel;
    public:
        ProcessManager(Kernel kernel) {}
    };

    /* Process  */
    struct PCB 
    {
        uint16_t ax; /* accumalator register */
        uint16_t bx; /* base register */
        uint16_t cx; /* count register */
        uint16_t dx;
        uint16_t sp;
        uint16_t bp;
        uint16_t si;
        uint16_t di;

        PCB(Process p);
    };

    enum ContextState
    {
        Ready,
        Running,
        New,
        Wait,
        Complete,
        Suspended,
    };
    class Process
    {
    private:
        /* Section fields such as Heap, Text and Stack */
        std::vector<uint16_t> pc_queue; // contains pc queue waiting to be executed
        std::vector<uint32_t> stack; 
        std::vector<uint32_t> data;
        std::vector<uint32_t> heap; // temporary before addition of memory
        /* size */
        size_t queueSZ;
        size_t stackSZ;
        size_t dataSZ;
        size_t heapSZ;
        /* Context data */
        uint16_t pc;
        uint32_t processID;
        ContextState state;
        PCB pcb;
    public:
        Process(uint32_t id) :pcb(*this) ,state(Ready), processID(id){}
    }; 
}
