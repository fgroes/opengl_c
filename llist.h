#ifndef LLIST_H
#define LLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct llist_element
{
	int index;
	struct llist_element *next;
	void *element;
};

typedef struct llist_element LLIST_ELEMENT;


struct llist
{
	int len;
	LLIST_ELEMENT *head, *tail, *curr;
};

typedef	struct llist LLIST; 


void llist_init(LLIST *);

void *llist_get_element(LLIST *, int);

void llist_add_element(LLIST *, void *);

void *llist_start(LLIST *);

void *llist_next(LLIST *);

bool llist_end(LLIST *);

void llist_delete(LLIST *);


#endif
