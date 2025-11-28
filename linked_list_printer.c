/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:08:06 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:08:06 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_list_from_head(t_list *lst)
{
	t_node	*curr;
	int		counter;

	if (list_checker(lst) == 0)
	{
		ft_printf("The list is empty\n");
		return ;
	}
	ft_printf("List Size: %d\n", lst->size);
	curr = lst->head;
	counter = 0;
	while (counter < lst->size)
	{
		ft_printf("%d - %d\n", counter, curr->value);
		counter++;
		curr = curr->next;
	}
	ft_printf("\n");
}

void	print_list_from_tail(t_list *lst)
{
	t_node	*curr;
	int		counter;

	if (list_checker(lst) == 0)
		return ;
	ft_printf("List Size: %d\n", lst->size);
	curr = lst->tail;
	counter = 0;
	while (counter < lst->size)
	{
		ft_printf("%d - %d\n", counter, curr->value);
		counter++;
		curr = curr->prev;
	}
	ft_printf("\n");
}
