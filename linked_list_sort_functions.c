/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_sort_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:17:08 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:17:08 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	do_indexing(t_list *stack_a)
{
	int		*tmp_arr;
	int		i;
	t_node	*curr;

	if (stack_a == NULL || stack_a->size == 0)
		return ;
	tmp_arr = (int *)malloc(sizeof(int) * stack_a->size);
	if (tmp_arr == NULL)
		return ;
	i = 0;
	curr = stack_a->head;
	while (curr != NULL)
	{
		tmp_arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
	bubble_sort(tmp_arr, stack_a->size);
	curr = stack_a->head;
	while (curr != NULL)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (curr->value == tmp_arr[i])
			{
				curr->value = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
	free(tmp_arr);
}

int	is_sorted(t_list *a)
{
	t_node	*curr;

	if (a == NULL || a->size < 2)
		return (1);
	curr = a->head;
	while (curr->next != NULL)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static int	get_max_bits(t_list *a)
{
	int	max_num;
	int	max_bits;

	max_num = a->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list *a, t_list *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;
	int	num;

	size = a->size;
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = a->head->value;
			if (((num >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
