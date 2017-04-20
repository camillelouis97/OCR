/* main.c: testing code */
 
# define _XOPEN_SOURCE 500
 
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
 
# include "list.h"

int main()
{
	struct list *l = malloc(sizeof(struct list));
	list_init(l);
	assert(list_len(l) == 0);
	assert(list_is_empty(l));
	for(int i = 0; i < 42; ++i)
	{
		struct list *tmp = malloc(sizeof(struct list));
		list_init(tmp);
		tmp->data = i;
		list_push_front(l, tmp);
		assert(l->next->data == i);
	}
	assert(list_len(l) == 42);
	return 0;
}
