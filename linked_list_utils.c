/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:19:14 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:19:14 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_checker(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (1);
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

int	single_arg_to_list(t_list *a, char *str)
{
	char	**arr_num;
	int		i;

	arr_num = ft_split(str, ' ');
	if (arr_num == NULL)
		return (0);
	i = 0;
	while (arr_num[i] != NULL)
		i++;
	if (str_to_list(arr_num, i, a) == NULL)
	{
		free_split(arr_num);
		return(0);
	}
	free_split(arr_num);
	return (1);
}

int	error()
{
	write(2, "Error\n", 6);
	return (1);
}
