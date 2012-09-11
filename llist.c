#include <stdlib.h>
#include <stdbool.h>
#include "llist.h"


void llist_init(LLIST *self)
{
	self->len = 0;
	self->head = NULL;
}


void llist_add_element(LLIST *self, void *element)
{
	LLIST_ELEMENT *temp;
	self->len += 1;
	temp = malloc(sizeof(LLIST_ELEMENT));
	temp->element = element;
	if (self->head == NULL)
		self->head = temp;
	else
		self->tail->next = temp;
	self->tail = temp;
	self->tail->next = NULL;
}


void *llist_start(LLIST *self)
{
	self->curr = self->head;
	return self->curr->element;
}


void *llist_get_next(LLIST *self)
{
	self->curr = self->curr->next;
	if (self->curr == NULL)
		return NULL;
	else
		return self->curr->element;
}


bool llist_end(LLIST *self)
{
	if (self->curr == NULL)
		return false;
	else
		return true;
}


void llist_delete(LLIST *self)
{
	LLIST_ELEMENT *temp;
	for (temp = self->head; temp != NULL; temp = temp->next)
		free(temp);
	self->len = 0;
	self->head = NULL;
}
