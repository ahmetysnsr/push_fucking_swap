/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:26:00 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:26:00 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *src, t_list *dst)
{
	int	value;

	if (!list_checker(src) || dst == NULL)
		return ;
	value = src->head->value;
	remove_front(src);
	add_front(dst, value);
}

void	swap(t_list *lst)
{
	int	tmp;

	if (!list_checker(lst) || lst->size < 2)
		return ;
	tmp = lst->head->value;
	lst->head->value = lst->head->next->value;
	lst->head->next->value = tmp;
}

void	rotate(t_list *lst)
{
	t_node	*old_head;
	t_node	*old_tail;

	if (list_checker(lst) == 0 || lst->size < 2)
		return ;
	old_head = lst->head;
	old_tail = lst->tail;
	lst->head = old_head->next;
	lst->head->prev = NULL;
	old_tail->next = old_head;
	old_head->prev = old_tail;
	old_head->next = NULL;
	lst->tail = old_head;
}

void	reverse_rotate(t_list *lst)
{
	t_node	*old_head;
	t_node	*old_tail;
	t_node	*new_tail;

	if (list_checker(lst) == 0 || lst->size < 2)
		return ;
	old_head = lst->head;
	old_tail = lst->tail;
	new_tail = old_tail->prev;
	new_tail->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = old_head;
	old_head->prev = old_tail;
	lst->head = old_tail;
	lst->tail = new_tail;
}
