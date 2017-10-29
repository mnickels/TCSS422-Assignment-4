/*
TCSS422 - Operating Systems
Problem 3

Group Members:
Taylor Riccetti
Alisher Baimenov
*/

#include <time.h>
#include "OS.h"


FIFO_Queue_p newProcesses;
PriorityQ_p readyProcesses;
PCB_p runningProcess;
FIFO_Queue_p dyingProcesses;
FIFO_Queue_p device1WaitingQueue;
FIFO_Queue_p device2WaitingQueue;

unsigned int sysStack;
unsigned int currentPC;
unsigned int dispatchCount;
PCB_p privilegedPCBs[4]; // array of PCBs
unsigned int privilegedCount;
unsigned int quantum;
unsigned int quantumCounter;
unsigned int processCounter;
int timer_counter;
int io_1_counter;
int io_2_counter;

// The os simulator, runs the main loop.
int OS_Simulator() {
    unsigned int iteration = 0;
    unsigned int totalIterations = 0;
    currentPC = 0;
    sysStack = 0;

    // make 10 processes to start out
    for (int i = 0; i < 10; i++) {
        createNewProcesses();
        processCounter += fifo_size(newProcesses);
    }

    // Main Loop
    // One cycle is one quantum
    for( ; ; ) { // for spider
        if (totalIterations > 225000) {        // 10 processes * 3000 instructions * 15 resets of pcb to zero / 2
            break;
        }

        if (!iteration) {
            currentPC = sysStack;
        }

        // // stops making processes after 48 and if there are at least 4 Privileged pcbs
        // if(processCounter < 48 && privilegedCount < 4) {
        //     createNewProcesses();
        //     processCounter += fifo_size(newProcesses);
        // }

        // Simulate Process Running
        if (currentPC >= get_max_pc(runningProcess)) {
            // reset currentPC to zero
            currentPC = 0;

            if (get_terminate(runningProcess)) {    // check if this process CAN die
                if (increment_term_count(runningProcess) >= get_terminate(runningProcess)) {
                    // this process has reset pc to zero enough, kill it
                    termination_trap();
                    iteration = 0;
                    continue;   // to skip rest of loop stuff and avoid breaking anything
                }
            }
        } else {
            // simulate one instruction being run
            currentPC++;
        }

        // check for timer interrupt
        if(timer()) {
            // Push to SysStack
            sysStack = currentPC;
            pseudoISR();
        }

        // checks for pending IO with completed tasks
        if (check_io_1()) {
            // does this happen in scheduler??
            PCB_p blocked_process = fifo_dequeue(device1WaitingQueue);
            set_state(blocked_process, ready);
            pq_enqueue(readyProcesses, blocked_process);
        }
        if (check_io_2()) {
            PCB_p blocked_process = fifo_dequeue(device2WaitingQueue);
            set_state(blocked_process, ready);
            pq_enqueue(readyProcesses, blocked_process);
        }

        // After current PC is incremented check each of the I/O arrays
        for (unsigned int i = 0; i < 4; i++) {
            if(currentPC == get_IO_1_trap(runningProcess, i)) {
                trapServiceHandler(1); // 1st io device
            } else if (currentPC == get_IO_2_trap(runningProcess, i)) {
                trapServiceHandler(2); // 2nd io device
            }
        }

        totalIterations++;
        if (iteration++ >= getCyclesFromPriority(get_priority(runningProcess))) {
            iteration = 0;
            quantumCounter--;
            pseudoISR();
        }
    }
}

// The psuedo-ISR, sets the state of the running process,
// calls the scheduler and updates the PC.
int pseudoISR() {

    // Sets the state to interrupted.
    set_state(runningProcess, interrupted);

    // save pc to pcb
    set_pc(runningProcess, currentPC);

    // scheduler up call
    scheduler(get_state(runningProcess));

    // IRET (update current pc)
    currentPC = sysStack;
    return SUCCESSFUL;
}

// Runs the scheduler to handle interrupts.
int scheduler(int interrupt) {
    // set new processes to ready
    while(!fifo_is_empty(newProcesses)) {
        // dequeue and print next pcb
        PCB_p pcb = fifo_dequeue(newProcesses);
        set_state(pcb, ready);

        // enqueue
        pq_enqueue(readyProcesses, pcb);
    }

    switch(interrupt) {
        case interrupted:
            dispatcher();
            break;
        case halted: // if the state is interrupted move to dying processes and then call the dispatcher.
            fifo_enqueue(dyingProcesses, runningProcess);
            dispatcher();
            break;
        case waiting + 2: // Device 1 IO
            fifo_enqueue(device1WaitingQueue, runningProcess);
            dispatcher();
            break;
        case waiting + 3: // Device 2 IO
            fifo_enqueue(device2WaitingQueue, runningProcess);
            break;
        default:
            // error handling as needed
            break;
    }

    // housekeeping if needed
    // If there are at least 10 terminated processes, clear them now.
    if(fifo_size(dyingProcesses) >= 10) {
        while(!fifo_is_empty(dyingProcesses)) {
            PCB_p dieingPCB = fifo_dequeue(dyingProcesses);
            destroy_pcb(dieingPCB);
        }
    }
    // after some time S move all processes into Q0.
    if(quantumCounter == 0) {
        moveProcesses();
        quantumCounter = quantum;
    }

    return SUCCESSFUL;
}

// Dispatched the running process to appropriate queue.
int dispatcher() {
    // increment and check
    dispatchCount++;

    // update context if the pcb was not halted or waiting.
    if(get_state(runningProcess) != halted
        && get_state(runningProcess) != waiting) {
        // update the pc counter.
        set_pc(runningProcess, sysStack);
        // set state.
        set_state(runningProcess, ready);

        unsigned char priority = get_priority(runningProcess);

        if (priority == MAX_PRIORITY) {
            set_priority(runningProcess, 0); // will go back to the highest priority queue
        } else {
            set_priority(runningProcess, priority + 1);
        }

        // enqueue
        pq_enqueue(readyProcesses, runningProcess);
    }

    // dequeue
    runningProcess = pq_dequeue(readyProcesses);

    // update state to running
    // set state
    set_state(runningProcess, running);

    sysStack = get_pc(runningProcess);

    return SUCCESSFUL;
}

int timer() {
    if (timer_counter <= 0) {
        // this means that a timer event has just fired last iteration; reset the timer to the CURRENT running process' quantum length
        if (runningProcess)
            timer_counter = getCyclesFromPriority(get_priority(runningProcess));
    }
    if (--timer_counter) {
        return 0;
    }
    // timer_counter == 0
    return 1;

    // // Decrements the cycles of the process.
    // unsigned int cycles = get_cycles(runningProcess);
    // unsigned char priority = get_priority(runningProcess);
    // set_cycles(runningProcess, cycles - 1);
    // if(cycles != 0) {
    //     return 0;
    // } // else if (cycles == 0) {
    // set_cycles(runningProcess, getCyclesFromPriority(priority));
    // return 1;
}

// IO trap handler
int trapServiceHandler(int device) {
    // Sets the state to waiting.
    set_state(runningProcess, waiting);

    // save pc to pcb
    set_pc(runningProcess, currentPC);

    // activate internal timer
    // TODO: add in support for multiple pcbs waiting on I/O
    unsigned int r = ((rand() % 3) + 3) * getCyclesFromPriority(get_priority(runningProcess));
    if (device == 1) {
        io_1_counter = r;
    } else if (device == 2) {
        io_2_counter = r;
    }

    // scheduler up call
    // if the device is one, the schedulers interrupt will be 6
    // if its two the scheduler will get 7
    scheduler(get_state(runningProcess) + (1 + device));

    return SUCCESSFUL;
}

int termination_trap() {
    set_pc(runningProcess, currentPC);  // should be zero
    set_state(runningProcess, halted);
    scheduler(halted);
}

int check_io_1() {
    if (fifo_is_empty(device1WaitingQueue)) {
        // nothing waiting on I/O
        return 0;
    }
    if (--io_1_counter) {
        return 0;
    }
    // there is at least one pcb in the device 1 queue, and io_1_counter has decremented to zero
    return 1;
}

int check_io_2() {
    if (fifo_is_empty(device2WaitingQueue)) {
        // nothing waiting on I/O
        return 0;
    }
    if (--io_2_counter) {
        return 0;
    }
    // there is at least one pcb in the device 2 queue, and io_2_counter has decremented to zero
    return 1;
}


void moveProcesses() {
    PriorityQ_p tempQueue = create_pq();
    while(!pq_isEmpty(readyProcesses)) {

        PCB_p tempPCB = pq_dequeue(readyProcesses);
        set_priority(tempPCB, 0);
        pq_enqueue(tempQueue, tempPCB);
    }

    readyProcesses = tempQueue;
}

// Creates a random number of processes to be added to the
// the list of new processes.
int createNewProcesses() {
    for(int i = 0; i < rand() % 5; i++) {
        PCB_p pcb = create_pcb();

        // 20% chance that the pcb will become privileged.
        if(rand() % 100 < 20 && privilegedCount < 4)  {
            // TODO setPrivileged(pcb); will we have a set 'terminate'
            privilegedPCBs[privilegedCount] = pcb;
            privilegedCount++;
        }
        fifo_enqueue(newProcesses, pcb);
    }
}

// Returns the number of cycles that each queue uses.
unsigned int getCyclesFromPriority(unsigned int priority) {
    return 2 * (priority + 1);
}

// Main, to jump start the OS simulation and initialize variables.
int main() {
    // Seed RNG
    srand(time(NULL));

    // Initialize Vars
    newProcesses = create_fifo_queue();
    readyProcesses = create_pq();
    runningProcess = create_pcb();
    dyingProcesses = create_fifo_queue();
    device1WaitingQueue = create_fifo_queue();
    device2WaitingQueue = create_fifo_queue();

    // set a process to running
    set_state(runningProcess, running);

    currentPC = 0;
    sysStack = 0;
    dispatchCount = 0;
    privilegedCount = 0;
    quantum = 3 * getCyclesFromPriority(7); // multiple of middle queues quantum size.
    quantumCounter = quantum;
    processCounter = 1;
    timer_counter = 0;

    // main loop
    OS_Simulator();

    // free resources
    destroy(device1WaitingQueue);
    destroy(device2WaitingQueue);
    destroy(newProcesses);
    destroy(dyingProcesses);
    destroy_pq(readyProcesses);
    destroy_pcb(runningProcess);
}
