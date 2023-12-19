#include "list.h"

void swap(t_list *a, t_list *b)
{
	int tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *cur = lst;

	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 and cur->next != 0)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = list;
	}
	return (lst);
}
