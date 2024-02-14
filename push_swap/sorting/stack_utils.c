#include "../push_swap.h"

bool sorted(stack **a)
{
	stack *tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

stack *stack_head(stack **a)
{
	if (!*a || !a)
		return (NULL);
	return (*a);
}

void print_stack(stack *s)
{
	if (s == NULL)
		return;
	stack *temp = s;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		if (temp->next != NULL)
			printf(" -> ");
		temp = temp->next;
	}
	printf("\n");
}

void free_stack(stack **a)
{
	stack *current;
	stack *next;

	current = *a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}

int stack_size(stack **a)
{
	if (!a || !*a)
		return (0);
	else
		return (1 + stack_size(&(*a)->next));
}