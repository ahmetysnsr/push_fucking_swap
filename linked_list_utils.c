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
