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
        ProcessManager(Kernel kernel);
        void RoundRobin();
    };

    /* Process */
    struct PCB 
    {
        uint8_t ax; /* accumalator register */
        uint16_t bx; /* base register */
        uint16_t cx; /* count register */
        uint16_t dx; /* data register */
        uint16_t sp; /* stack pointer */
        uint16_t bp; /* base pointer */
        uint16_t si; /* source index */
        uint16_t di; /* destination index */

        PCB(Process* p);
    };

    enum ProcessState
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
        uint16_t processID;
        ProcessState state;
        PCB pcb;
    public:
        /* Context data */
        uint16_t getprocessID();
        ProcessState getstate();
        inline std::vector<uint16_t> getpc_queue(){ return this->pc_queue; };
        inline std::vector<uint32_t> getstack(){ return this->stack; }; 
        inline std::vector<uint32_t> getdata(){ return this->data; };
        inline std::vector<uint32_t> getheap(){ return this->heap; };
        PCB pcb;
    }; 
}
