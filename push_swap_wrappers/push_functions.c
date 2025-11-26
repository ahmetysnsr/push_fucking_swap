/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:08:49 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 16:10:24 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	pa(list *a, list *b)
{
	if (b == NULL || b->size == 0)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(list *a, list *b)
{
	if (a == NULL || a->size == 0)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}
