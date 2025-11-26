/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:33:01 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:34:11 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	sa(list *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(list *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(list *a, list *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
