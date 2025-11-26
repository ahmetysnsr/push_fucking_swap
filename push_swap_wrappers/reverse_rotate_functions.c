/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:07:50 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 16:23:57 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../push_swap.h"

void	rra(t_list *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list *a, t_list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
