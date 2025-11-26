/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_init_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:06:03 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:06:03 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static node	*create_node(int value)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

list	*create_list_with_value(int value)
{
	list	*new_list;
	node	*new_node;

	new_node = create_node(value);
	if (new_node == NULL)
		return (NULL);
	new_list = (list *)malloc(sizeof(list));
	if (new_list == NULL)
		return (NULL);
	new_list->head = new_node;
	new_list->tail = new_node;
	new_list->size = 1;
	return (new_list);
}

list	*create_list(void)
{
	list	*new_list;

	new_list = (list *)malloc(sizeof(list));
	if (new_list == NULL)
		return (NULL);
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->size = 0;
	return (new_list);
}
