/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_remove_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:12:45 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:12:45 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*remove_front(t_list *lst)
{
	t_node	*old_head;

	if (list_checker(lst) == 0)
		return (NULL);
	old_head = lst->head;
	if (lst->size == 1)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else
	{
		lst->head = old_head->next;
		lst->head->prev = NULL;
	}
	lst->size--;
	free(old_head);
	return (lst);
}

t_list	*remove_back(t_list *lst)
{
	t_node	*old_tail;

	if (list_checker(lst) == 0)
		return (NULL);
	old_tail = lst->tail;
	if (lst->size == 1)
	{
		lst->tail = NULL;
		lst->head = NULL;
	}
	else
	{
		lst->tail = old_tail->prev;
		lst->tail->next = NULL;
	}
	lst->size--;
	free(old_tail);
	return (lst);
}

void	delete_list(t_list *lst)
{
	t_node	*n;
	t_node	*tmp;

	if (lst == NULL)
		return ;
	n = lst->head;
	while (n != NULL)
	{
		tmp = n;
		n = n->next;
		free(tmp);
	}
	free(lst);
}
