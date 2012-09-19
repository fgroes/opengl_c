#include "llist.h"


void llist_init(LLIST *self)
{
	self->len = 0;
	self->head = NULL;
	self->tail = self->head;
	self->curr = self->head;
}


void *llist_get_element(LLIST *self, int index)
{
	if (self->len == 0)
	{
		printf("error: no element in list\n");
		void *temp = NULL;
		return temp;
	}
	else
	{
		if (self->curr->index == index)
			return self->curr->element;
		else if (index < self->curr->index)
			self->curr = self->head;
		int i;
		for (i = self->curr->index; i < index; i++)
			self->curr = self->curr->next;
		return self->curr->element;
	}
}


void llist_add_element(LLIST *self, void *element)
{
	LLIST_ELEMENT *temp;
	temp = malloc(sizeof(LLIST_ELEMENT));
	temp->element = element;
	temp->index = self->len;
	self->len += 1;
	if (self->head == NULL)
	{
		self->head = temp;
		self->head->index = 0;
	}
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


void *llist_next(LLIST *self)
{
	self->curr = self->curr->next;
	if (self->curr == NULL)
	{
		return NULL;
	}
	else
		return self->curr->element;
}


bool llist_end(LLIST *self)
{
	if (self->curr == NULL)
	{
		self->curr = self->tail;
		return false;
	}
	else
		return true;
}


void llist_delete(LLIST *self)
{
	LLIST_ELEMENT *temp;
	for (temp = self->head; temp != NULL; temp = temp->next)
		free(temp->element);
		free(temp);
	self->len = 0;
	self->head = NULL;
	self->tail = self->head;
	self->curr = self->head;
}
