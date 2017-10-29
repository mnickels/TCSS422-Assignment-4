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

#ifndef PCB_H
#define PCB_H

// Pointer to the cpu_context structure.
typedef struct CPU_context_s *CPU_context_p;

typedef struct PCB_s * PCB_p;

enum state_type {new, ready, running, interrupted, waiting, halted};

/* constructor */
// Creates a pcb with the PCB pointer and the CPU_context pointer
PCB_p create_pcb();

/* deconstructor */
// Deallocates the memory for the pcb passed in.
void destroy_pcb(PCB_p p);

/* functions */
// Assigns the PID.
void set_pid(PCB_p pcb, unsigned int num);

// Returns the pid of the pcb.
unsigned int get_pid(PCB_p pcb);

// Sets the state_type of the pcb passed in.
void set_state(PCB_p pcb, enum state_type type);

// Returns the state of the pcb.
enum state_type get_state(PCB_p pcb);

// Sets the priority of the pcb.
void set_priority(PCB_p pcb, unsigned char priority);

// gets the priority of the pcb.
unsigned char get_priority(PCB_p pcb);

// returns the pcbs pc value.
unsigned int get_pc(PCB_p pcb);

// Sets the pcbs pc value to the given pc.
void set_pc(PCB_p pcb, unsigned int pc);

// Returns whether or no the pcb is privileged.
int isPrivileged(PCB_p pcb);

// Sets the pcb to privileged.
void setPrivileged(PCB_p pcb);

//Returns the i/o 1 trap's value at the given index.
unsigned int get_IO_1_trap(PCB_p pcb, int index);

//Returns the i/o 2 trap's value at the given index.
unsigned int get_IO_2_trap(PCB_p pcb, int index);

unsigned int get_terminate(PCB_p);

unsigned int get_term_count(PCB_p);

unsigned int increment_term_count(PCB_p);

unsigned int get_max_pc(PCB_p);

// Prints a string representation of the pcb passed in.
void print_pcb_file(PCB_p pcb, FILE * fp);

void print_pcb(PCB_p pcb);

void print_context(CPU_context_p context, FILE * fp);

const char* get_state_name(enum state_type state);

#endif
