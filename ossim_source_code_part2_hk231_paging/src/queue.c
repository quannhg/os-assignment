#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
        if (q == NULL || proc == NULL)
                return; // check for null pointers

        if (q->size >= MAX_QUEUE_SIZE)
        {
                printf("Queue is full!\n");
                return;
        }

        q->proc[q->size] = proc; // add process to end of array
        q->size++;               // increment queue size
}

struct pcb_t *dequeue(struct queue_t *q)
{
        if (q == NULL || q->size == 0)
                return NULL; // check for empty queue

        struct pcb_t *first_proc = q->proc[0];

        // remove first process from queue
        for (int i = 0; i < q->size - 1; i++)
        {
                q->proc[i] = q->proc[i + 1];
        }

        q->size--; // decrement queue size

        return first_proc;
}
