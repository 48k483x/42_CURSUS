
#include "../push_swap.h"

bool	sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

t_stack	*stack_head(t_stack **a)
{
	if (!*a || !a)
		return (NULL);
	return (*a);
}

void	print_stack(t_stack *s)
{
	t_stack	*temp;

	if (s == NULL)
		return ;
	temp = s;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		if (temp->next != NULL)
			printf(" -> ");
		temp = temp->next;
	}
	printf("\n");
}

void	free_stack(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	current = *a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}

int	stack_size(t_stack **a)
{
	if (!a || !*a)
		return (0);
	else
		return (1 + stack_size(&(*a)->next));
}
