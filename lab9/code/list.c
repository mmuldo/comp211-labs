/*
 * Spring 2019, COMP 211: Lab 9
 *
 * Linked lists
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list create()
{
	list l;
	l.head = NULL;
	return l;
}

bool is_empty(list *l)
{
	if (l->head == NULL) {
		return true;
	} else {
		return false;
	}
}

void insert(list *l, int loc, char c)
{
	node *new = malloc(sizeof(node));
	new->data = c;
	new->next = NULL;

	if (loc == 0) {
		new->next = l->head;
		l->head = new;
		return;
	}

	node* tmp = l->head;
	while (loc > 1) {
		tmp = tmp->next;
		loc--;
	}

	new->next = tmp->next;
	tmp->next = new;
}

char deletion(list *l, int loc)
{
	node *tmp_next = l->head->next;
	char c;
	if (loc == 0) {
		c = l->head->data;
		free(l->head);
		l->head = tmp_next;
		return c;
	}

	node *tmp = l->head;
	while (loc > 1) {
		tmp = tmp->next;
		loc--;
	}
	c = tmp->next->data;
	tmp_next = tmp->next->next;
	free(tmp->next);
	tmp->next = tmp_next;
	return c;
}

char getval(list *l, int loc)
{
	node *tmp = l->head;
	while (loc > 0) {
		tmp = tmp->next;
		loc--;
	}

	return tmp->data;
}

int size(list *l)
{
	int len = 0;
	node* tmp = l->head;

	while (tmp != NULL) {
		tmp = tmp->next;
		len++;
	}
	return len;
}

void print(list *l)
{
	// List is empty, cannot print
	if (is_empty(l)) return;

	// List is not empty, print
	node *node = l->head;
	while (node != NULL) {
		printf("%c ", node->data);
		node = node->next;
	}
	printf("\n");
}
