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
	struct list *tmp = list->next;
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

void list_append(struct list *list, struct list *elm)
{
  struct list *_list = list;
  while (_list->next)
    _list = _list->next;
  _list->next = elm;
}
