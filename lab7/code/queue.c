/*
 * Spring 2019, COMP 211: Lab 7
 * Structs, pointers and queues
 *
 * This file implements functions required for queue operations
 */
#include "queue.h"

//-----------------------------------------------------------------
// Functions for simple queue implementation using array
//-----------------------------------------------------------------
void queue_new(queue *Qptr)
{
	Qptr->front = 0;
	Qptr->back = 0;
}

bool queue_empty(queue *Qptr)
{
	return Qptr->front == Qptr->back;
}

void enqueue(queue *Qptr, char c)
{
	if (Qptr->back < MAX_QUEUE_LEN) {
		Qptr->data[Qptr->back] = c;
		Qptr->back++;
	} else {
		printf("Error: out of space in queue\n");
	}
}

char dequeue(queue *Qptr)
{
	if (queue_empty(Qptr)) return -1;

	char c = Qptr->data[Qptr->front];

	for (int i=Qptr->front; i < Qptr->back-1; i++) {
		Qptr->data[i] = Qptr->data[i+1];
	}
	Qptr->back--;

	return c;
}

void queue_print(queue *Qptr)
{
	for (int i=Qptr->front; i < Qptr->back; i++) {
		printf("%c, ", Qptr->data[i]);
	}
	printf("\n");
}

//-----------------------------------------------------------------
// Functions for queue implementation using circular array
//-----------------------------------------------------------------
void queue_new_circ(queue *Qptr)
{
	Qptr->front = 0;
	Qptr->back = 0;
	for (int i=0; i<MAX_QUEUE_LEN; i++) {
		Qptr->data[i] = '\0';
	}
}

bool queue_empty_circ(queue *Qptr)
{
	return Qptr->front == Qptr->back && Qptr->data[Qptr->front] == '\0';
}

bool queue_full_circ(queue *Qptr)
{
	return Qptr->front == Qptr->back && Qptr->data[Qptr->front] != '\0';
}

void enqueue_circ(queue *Qptr, char c)
{
	if (!queue_full_circ(Qptr)) {
		Qptr->data[Qptr->back] = c;

		if (Qptr->back < MAX_QUEUE_LEN-1) {
			Qptr->back++;
		} else {
			Qptr->back = 0;
		}
	} else {
		printf("Error: out of space in queue\n");
	}
}

char dequeue_circ(queue *Qptr)
{
	if (queue_empty_circ(Qptr)) return -1;

	char c = Qptr->data[Qptr->front];
	Qptr->data[Qptr->front] = '\0';
	Qptr->front++;

	return c;
}

int get_qlen_circ(queue *Qptr)
{
	return 0;
}

void queue_print_circ(queue *Qptr)
{
	if (queue_empty_circ(Qptr)) return;

	if (Qptr->front < Qptr->back) {
		for (int i=Qptr->front; i < Qptr->back; i++) {
			printf("%c, ", Qptr->data[i]);
		}
	} else {
		for (int i=Qptr->front; i < MAX_QUEUE_LEN; i++) {
			printf("%c, ", Qptr->data[i]);
		}
		for (int i=0; i < Qptr->back; i++) {
			printf("%c, ", Qptr->data[i]);
		}
	}
	printf("\n");
}

