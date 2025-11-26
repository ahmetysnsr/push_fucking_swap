/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:07:59 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 16:23:57 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../push_swap.h"

void	rb(t_list *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_list *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rr(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
