/*
TCSS422 - Operating Systems
Problem 3

Group Members:
Taylor Riccetti
Alisher Baimenov

Changes:
    We added to variables the the PCB_s struct, a bool value to
    determine whether or not the PCB is privileged and added
    a cycles variable to track how many cycles the PCB has run.

    This information is specific to the PCB so we decided to store this
    information here.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "pcb.h"

// Global to determine the next possible PID value for a new PCB
unsigned int currentpid = 1;

// Structure definition for the CPU State for the LC-3 Processor.
struct CPU_context_s {
    unsigned int pc;
    unsigned int ir;
    unsigned int psr;
    unsigned int r0;
    unsigned int r1;
    unsigned int r2;
    unsigned int r3;
    unsigned int r4;
    unsigned int r5;
    unsigned int r6;
    unsigned int r7;
} CPU_context_s;

// Structure definition for the process control block.
struct PCB_s {
    unsigned int pid;
    enum state_type state;
    unsigned int parent;
    unsigned char priority;
    unsigned char *mem;
    unsigned int size;
    unsigned char channel_no;
    CPU_context_p context;
    unsigned int max_pc;
    time_t creation;
    time_t termination;
    unsigned int terminate;
    unsigned int term_count;
    unsigned int IO_1_trap[4];
    unsigned int IO_2_trap[4];
} PCB_s;

/* constructor */
// Creates a pcb with the PCB pointer and the CPU_context pointer
PCB_p create_pcb() {
    PCB_p pcb = (PCB_p) malloc(sizeof(PCB_s));
    pcb->context = (CPU_context_p) malloc(sizeof(CPU_context_s));
    if (!pcb) {
        return NULL;
    } else {
        pcb->context->pc = 0;
        pcb->context->ir = 0;
        pcb->context->psr = 0;
        pcb->context->r0 = 0;
        pcb->context->r1 = 0;
        pcb->context->r2 = 0;
        pcb->context->r3 = 0;
        pcb->context->r4 = 0;
        pcb->context->r5 = 0;
        pcb->context->r6 = 0;
        pcb->context->r7 = 0;

        pcb->pid = currentpid++;
        pcb->state = new;
        pcb->parent = 0;
        pcb->priority = 0;
        pcb->mem = 0;
        pcb->size = 0;
        pcb->channel_no = 0;
        // PCB Fields added for problem 4.

        srand(time(NULL));
        pcb->max_pc = rand() % 2001 + 1000;     // rand from 2000 - 3000, inclusive
        pcb->creation = time(NULL);
        pcb->termination = 0;
        pcb->terminate = rand() % 16;     // rand from 0 - 15, inclusive
        pcb->term_count = 0;

        for (int i = 0; i < 4; i++) {
            unsigned int r = rand() % pcb->max_pc;
            int duplicate_flag = 0;
            for (int j = 0; j < i; j++) {
                duplicate_flag |= pcb->IO_1_trap[j] == r;
            }
            if (duplicate_flag) {
                i--;
            } else {
                pcb->IO_1_trap[i] = r;
            }
        }
        for (int i = 0; i < 4; i++) {
            unsigned int r = rand() % pcb->max_pc;
            int duplicate_flag = 0;
            for (int j = 0; j < i; j++) {
                duplicate_flag |= pcb->IO_2_trap[j] == r;
            }
            // make sure io1 and io2 dont overlap, either
            for (int j = 0; j < 4; j++) {
                duplicate_flag |= pcb->IO_1_trap[j] == r;
            }
            if (duplicate_flag) {
                i--;
            } else {
                pcb->IO_2_trap[i] = r;
            }
        }
    }
    return pcb;
}

/* deconstructor */
// Deallocates the memory for the pcb passed in.
void destroy_pcb(PCB_p p) {
    if (!p) {
        return;
    } else {
        free(p->context);
        free(p);
    }
}

/* functions */
// Assigns the PID.
void set_pid(PCB_p pcb, unsigned int num) {
    pcb->pid = num;
}

unsigned int get_pid(PCB_p pcb) {
    return pcb->pid;
}

// Sets the state_type of the pcb passed in.
void set_state(PCB_p pcb, enum state_type type) {
    pcb->state = type;
}

enum state_type get_state(PCB_p pcb) {
    return pcb->state;
}

// Sets the priority of the pcb.
void set_priority(PCB_p pcb, unsigned char priority) {
    pcb->priority = priority;
}

unsigned char get_priority(PCB_p pcb) {
    return pcb->priority;
}

// returns the pcbs pc value.
unsigned int get_pc(PCB_p pcb) {
    if(pcb == NULL) return -1;
    if(pcb->context == NULL) return -1;

    return pcb->context->pc;
}

// Sets the pcbs pc value to the given pc.
void set_pc(PCB_p pcb, unsigned int pc) {
    pcb->context->pc = pc;
}

// Sets the pcb's time to the current time.
void set_termination(PCB_p pcb) {
    if (pcb == NULL) return;
    pcb->termination = time(NULL);
}

//Returns the i/o 1 trap's value at the given index.
unsigned int get_IO_1_trap(PCB_p pcb, int index) {
    return pcb->IO_1_trap[index];
}

//Returns the i/o 2 trap's value at the given index.
unsigned int get_IO_2_trap(PCB_p pcb, int index) {
    return pcb->IO_2_trap[index];
}

unsigned int get_terminate(PCB_p pcb) {
    return pcb->terminate;
}

unsigned int get_term_count(PCB_p pcb) {
    return pcb->term_count;
}

unsigned int increment_term_count(PCB_p pcb) {
    return ++pcb->term_count;
}

unsigned int get_max_pc(PCB_p pcb) {
    return pcb->max_pc;
}

// Prints a string representation of the pcb passed in.
void print_pcb_file(PCB_p pcb, FILE * fp) {
    fprintf(fp, "Pid: %X, Priority: %X, State:%X ", get_pid(pcb), get_priority(pcb), pcb->state);
    print_context(pcb->context,fp);
}

void print_pcb(PCB_p pcb){
    printf("PCB: PID: %u, PRIORITY: %u, PC: %u\n", pcb->pid, pcb->priority, pcb->context->pc);
}

void print_context(CPU_context_p context, FILE * fp) {
    fprintf(fp, "Context Data: [pc: %u, ir: %u, psr: %u, r0: %u, r1: %u, r2: %u, r3: %u, r4: %u, r5: %u, r6: %u, r7: %u]\n",
           context->pc, context->ir, context->psr, context->r0, context->r1, context->r2, context->r3,
           context->r4, context->r5, context->r6, context->r7);
}

const char* get_state_name(enum state_type state) {
    switch (state) {
        case new: return "New";
        case ready: return "Ready";
        case running: return "Running";
        case interrupted: return "Interrupted";
        case waiting: return "Waiting";
        case halted: return "Halted";
    }
}
