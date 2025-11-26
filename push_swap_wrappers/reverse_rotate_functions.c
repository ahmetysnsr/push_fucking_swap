/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:07:50 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 16:19:03 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../push_swap.h"

void	rra(list *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(list *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(list *a, list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
