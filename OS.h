/*
	Mike Nickels
	Taylor Riccetti
	TCSS 422
	Problem 4
*/

#include <stdio.h>
#include <stdlib.h>
#include "fifo_queue.h"
#include "pcb.h"
#include "PriorityQ.h"

// value to denote current interupt is a timer interupt
#define TIMER_INTERUPT 1

// value to denote a successful function return
#define SUCCESSFUL 0

// Maximum size used for an ouput buffer string
#define MAX_BUFFER_SIZE 1024

// Simulates the OS.
int OS_Simulator();

// Runs the pseudo ISR, calls the scheduler and updates the PC.
int pseudoISR();

// The I/O Trap Handler.
int trapServiceHandler(int);

// Handles the interrupts.
int scheduler(int);

// Dispatches the next ready process and enqueues the old process.
int dispatcher();

// The timer calls timer interrupts.
int timer();

int termination_trap();

int check_io_1();

int check_io_2();

// Creates a random number (0 - 5) of processes.
int createNewProcesses();

void createPrivilegedProcesses();

// Moves proccesses into the highest priority queue.
void moveProcesses();

// Returns the number of cycles that each queue uses.
unsigned int getCyclesFromPriority(unsigned int);
