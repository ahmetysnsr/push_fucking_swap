/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:07:59 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 16:19:06 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../push_swap.h"

void	rb(list *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(list *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rr(list *a, list *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
