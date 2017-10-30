/*
	Mike Nickels
	Taylor Riccetti
	TCSS 422
	Problem 4
*/

#include <stdio.h>
#include <stdlib.h>
#include "PriorityQ.h"
#include "fifo_queue.h"

struct PriorityQ_s {
	FIFO_Queue_p priorities[MAX_PRIORITY + 1];
	unsigned int count;
} PriorityQ_s;

PriorityQ_p create_pq() {
	PriorityQ_p queue = malloc(sizeof(struct PriorityQ_s));
	if(queue == 0)
	{
		return 0;
	}
	int i;
	for(i = 0; i <= MAX_PRIORITY; i++)
	{
		queue->priorities[i] = create_fifo_queue();
    }
    queue->count = 0;
	return queue;
}

/* returns 0 for false, 1 for true */
int pq_isEmpty(PriorityQ_p queue)
{
	return queue->count == 0;
}

unsigned int pq_size(PriorityQ_p queue) {
	return queue->count;
}

void pq_enqueue(PriorityQ_p queue, PCB_p data)
{
    int priority = get_priority(data);
    queue->count++;
	fifo_enqueue(queue->priorities[priority], data);
}

PCB_p pq_dequeue(PriorityQ_p queue)
{
	int i;
	for(i = 0; i <= MAX_PRIORITY; i++)
	{
		if(fifo_size(queue->priorities[i]) > 0)
		{
			PCB_p removed_node = fifo_dequeue(queue->priorities[i]);
			queue->count--;
			return removed_node;
		}
	}
	return NULL;
}

void print_pq(PriorityQ_p queue)
{
	int i;
	for(i = 0; i <= MAX_PRIORITY; i++)
	{
		FIFO_Queue_p fifo = queue->priorities[i];
		printf("Q%d:", i);
        print_fifo_queue(fifo);
		printf("\n");
	}
}

void print_priority_queue(PriorityQ_p queue) {
    for(int i = 0; i <= MAX_PRIORITY; i++) {
        printf("Q%u: %d\n", i, fifo_size(queue->priorities[i]));
    }
}

void destroy_pq(PriorityQ_p queue) {
	while(pq_isEmpty(queue) == 0)
	{
		pq_dequeue(queue);
	}
	free(queue);
}
