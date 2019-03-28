/*
 * Spring 2019, COMP 211: Lab 7
 * Structs, pointers and queues
 *
 * Driver code to work with queue data structure.
 */

#include "queue.h"

int main()
{
    // Test basic queue
    printf("--------- Testing basic queue ---------\n");
    queue Q;
    queue_new(&Q);
    queue_empty(&Q);
    enqueue(&Q, 'a');
    enqueue(&Q, 'b');
    enqueue(&Q, 'c');
    enqueue(&Q, 'd');
    enqueue(&Q, 'e');
    enqueue(&Q, 'f');
    enqueue(&Q, 'g');
    enqueue(&Q, 'h');
    enqueue(&Q, 'i');
    queue_print(&Q);
    enqueue(&Q, 'j');
    queue_print(&Q);
    queue_empty(&Q);
    enqueue(&Q, 'k');
    queue_print(&Q);
    enqueue(&Q, 'l');
    queue_print(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    enqueue(&Q,'7');
    queue_print(&Q);

    // Test queue created using circular array
    printf("--------- Testing queue using circular array ---------\n");
    queue_new_circ(&Q);
    queue_empty_circ(&Q);
    enqueue_circ(&Q, 'a');
    enqueue_circ(&Q, 'b');
    enqueue_circ(&Q, 'c');
    enqueue_circ(&Q, 'd');
    enqueue_circ(&Q, 'e');
    enqueue_circ(&Q, 'f');
    enqueue_circ(&Q, 'g');
    enqueue_circ(&Q, 'h');
    enqueue_circ(&Q, 'i');
    queue_print_circ(&Q);
    enqueue_circ(&Q, 'j');
    queue_print_circ(&Q);
    queue_empty_circ(&Q);
    enqueue_circ(&Q, 'k');
    queue_print_circ(&Q);
    enqueue_circ(&Q, 'l');
    queue_print_circ(&Q);

    dequeue_circ(&Q);
    dequeue_circ(&Q);
    dequeue_circ(&Q);
    enqueue_circ(&Q,'7');
    queue_print_circ(&Q);

}
