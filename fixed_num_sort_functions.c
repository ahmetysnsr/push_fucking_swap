#include "push_swap.h"

static int	get_max_value(t_list *stack)
{
	int		max;
	t_node	*curr;

	curr = stack->head;
	max = curr->value;
	while (curr)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
	}
	return (max);
}

static int	get_min_index(t_list *stack)
{
	int		min;
	int		min_index;
	int		i;
	t_node	*curr;

	curr = stack->head;
	min = curr->value;
	min_index = 0;
	i = 0;
	while (curr)
	{
		if (curr->value < min)
		{
			min = curr->value;
			min_index = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_index);
}

void	sort_three(t_list *a)
{
	int	max;

	if (is_sorted(a))
		return ;
	max = get_max_value(a);
	if (a->head->value == max)
		ra(a);
	else if (a->head->next->value == max)
		rra(a);
	if (a->head->value > a->head->next->value)
		sa(a);
}

void	sort_five(t_list *a, t_list *b)
{
	int	min_idx;

	while (a->size > 3)
	{
		min_idx = get_min_index(a);
		if (min_idx <= a->size / 2)
		{
			while (min_idx-- > 0)
				ra(a);
		}
		else
		{
			while (min_idx++ < a->size)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
