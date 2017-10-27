/*
TCSS422 - Operating Systems
Problem 3

Group Members:
Taylor Riccetti
Alisher Baimenov
*/

#ifndef PRIORITYQ_H_
#define PRIORITYQ_H_

#include "fifo_queue.h"
#include "pcb.h"

// The maximum priority allowed for a process
#define MAX_PRIORITY 15

typedef struct PriorityQ_s * PriorityQ_p;

PriorityQ_p create_pq();

void destroy_pq(PriorityQ_p queue);

int pq_isEmpty(PriorityQ_p queue);

unsigned int pq_size(PriorityQ_p queue);

void pq_enqueue(PriorityQ_p queue, PCB_p data);

PCB_p pq_dequeue(PriorityQ_p queue);

void print_pq(PriorityQ_p queue);

void print_priority_queue(PriorityQ_p queue);

#endif /* PRIORITYQ_H_ */
