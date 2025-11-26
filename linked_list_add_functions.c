/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_add_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:03:14 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:03:14 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_first_value(t_list *lst, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	lst->tail = new_node;
	lst->head = new_node;
	lst->size++;
	return (new_node);
}

t_node	*add_front(t_list *lst, int value)
{
	t_node	*old_head;
	t_node	*new_head;

	if (lst->size == 0)
		return (create_first_value(lst, value));
	new_head = (t_node *)malloc(sizeof(t_node));
	if (new_head == NULL)
		return (NULL);
	new_head->value = value;
	new_head->prev = NULL;
	old_head = lst->head;
	old_head->prev = new_head;
	new_head->next = old_head;
	lst->head = new_head;
	lst->size++;
	return (new_head);
}

t_node	*add_back(t_list *lst, int value)
{
	t_node	*old_tail;
	t_node	*new_tail;

	if (lst->size == 0)
		return (create_first_value(lst, value));
	new_tail = (t_node *)malloc(sizeof(t_node));
	if (new_tail == NULL)
		return (NULL);
	new_tail->value = value;
	old_tail = lst->tail;
	new_tail->next = NULL;
	old_tail->next = new_tail;
	new_tail->prev = old_tail;
	lst->tail = new_tail;
	lst->size++;
	return (new_tail);
}
