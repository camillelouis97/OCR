/* list.c */

# define _XOPEN_SOURCE 500

# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
 
# include "list.h"

void list_init(struct list *list)
{
	list->next = NULL;
}

int list_is_empty(struct list *list)
{
	return list->next == NULL;
}

size_t list_len(struct list *list)
{
	size_t len = 0;
	while(list->next)
	{
		len++;
		list = list->next;
	}
	return len;
}

void list_push_front(struct list *list, struct list *elm)
{
	int* tmp = list->next;
	list->next = elm;
	elm->next = tmp;
}

struct list* list_pop_front(struct list *list)
{
	struct list* tmp = list->next;
	list->next = tmp->next;
	tmp->next = NULL;
	return tmp;
}

struct list* list_find(struct list *list, int value)
{
	while(list->next && list->data != value)
		list = list->next;
	return list->data == value ? list : NULL;
}

int list_is_sorted(struct list *list)
{
	while(list->next && list->data <= list->next->data)
		list = list->next;
	return list->next == NULL;
}

void list_insert(struct list *list, struct list *elm)
{
	while(list->next && list->data < elm->data)
		list = list->next;
	if(list->next)
		elm->next = list->next;
	list->next = elm;
}
