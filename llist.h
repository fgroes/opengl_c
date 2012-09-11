#ifndef LLIST_H
#define LLIST_H
#include <stdbool.h>


struct llist_element
{
	//int index;
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


void llist_init(LLIST *self);

void llist_add_element(LLIST *self, void *element);

void *llist_start(LLIST *self);

void *llist_get_next(LLIST *self);

bool llist_end(LLIST *self);

void llist_delete(LLIST *self);


#endif
