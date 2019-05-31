/* COMP 211, Spring 2019
 * Lab10
 *
 * Dummy head nodes and doubly linked lists
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

//===============================================================
//
// Singly-linked list functions
//
//===============================================================
list create() {

	// Create dummy head node
	node *n = (node*)malloc(sizeof(node));
	n->data = '\0';
	n->next = NULL;

	// Add dummy head node to head of list
	list l;
	l.head = n;
	return l;
}

bool is_empty(list *l) {

	if (l->head->next == NULL) {
		return true;
	}
	return false;
}

void insert(list *l, int loc, char c) {

	// Create new node to add
	node *n = (node*)malloc(sizeof(node));
	n->data = c;

	// Insert node
	node *tmp = l->head;
	for(int i=0; tmp->next != NULL && i < loc; i++) {
		tmp = tmp->next;
	}
	n->next = tmp->next;
	tmp->next = n;
}

char deletion(list *l, int loc) {

	char result = -1;
	
	// Delete node
	node *tmp = l->head;
	for (int i=0; tmp->next !=NULL && i < loc; i++) {
		tmp = tmp->next;
	}

	if (tmp->next == NULL) return -1;
	
	node *del = tmp->next;
	tmp->next = tmp->next->next;
	result = del->data;
	free(del);

	return result;
}

char getval(list *l, int loc) {

	node *tmp = l->head;
	for (int i=0; tmp->next != NULL && i < loc; i++) {
		tmp = tmp->next;
	}

	return (tmp->next == NULL) ? -1 : tmp->next->data;
}

int size(list *l) {

	node *tmp = l->head;
	int count = 0;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		count++;
	}
	return count;
}

void print(list *l) {

	node *node = l->head->next;
	while (node != NULL) {
		printf("%c ", node->data);
		node = node->next;
	}
	printf("\n");
}

//===============================================================
//
// Doubly-linked list functions
//
//===============================================================
dlist dlist_create() {

	// Create dummy head node
	dnode *n1 = (dnode*)malloc(sizeof(dnode));
	n1->data = '\0';
	n1->prev = NULL;

	// Create dummy tail node
	dnode *n2 = (dnode*)malloc(sizeof(dnode));
	n2->data = '\0';
	n2->next = NULL;

	// Connect up head and tail
	n1->next = n2;
	n2->prev = n1;

	// Add dummy head node to head of list
	dlist l;
	l.head = n1;
	l.tail = n2;
	return l;
}

bool dlist_is_empty(dlist *l) {

	if (l->head->next->next == NULL) {
		return true;
	}
	return false;
}

void dlist_insert(dlist *l, int loc, char c) {

	// Create new node to add
	dnode *n = (dnode*)malloc(sizeof(dnode));
	n->data = c;

	// Insert node
	dnode *tmp = l->head;
	for (int i=0; tmp->next != NULL && i < loc; i++) {
		tmp = tmp->next;
	}

	n->next = tmp->next;
	tmp->next->prev = n;
	n->prev = tmp;
	tmp->next = n;

}

char dlist_deletion(dlist *l, int loc) {

	char result = -1;
	
	// Delete node
	dnode *tmp = l->head;
	for (int i=0; tmp->next !=NULL && i < loc; i++) {
		tmp = tmp->next;
	}

	if (tmp->next == NULL) return -1;
	
	dnode *del = tmp->next;
	tmp->next = tmp->next->next;
	tmp->next->prev = tmp;
	result = del->data;
	free(del);

	return result;
}

char dlist_getval(dlist *l, int loc) {

	dnode *tmp = l->head;
	for (int i=0; tmp->next != NULL && i < loc; i++) {
		tmp = tmp->next;
	}
	return (tmp->next == NULL) ? -1 : tmp->next->data;
}

int dlist_size(dlist *l) {
	int count = 0;
	dnode *tmp = l->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		count++;
	}
	return count;
}

void dlist_print(dlist *l) {

	// Print list forwards
	printf("printing list forwards\n");
	dnode *node = l->head->next;
	while (node->next != NULL) {
		printf("%c ", node->data);
		node = node->next;
	}
	printf("\n");

	// Print list backwards
	printf("printing list backwards\n");
	node = l->tail->prev;
	while (node->prev != NULL) {
		printf("%c ", node->data);
		node = node->prev;
	}
	printf("\n");
}
