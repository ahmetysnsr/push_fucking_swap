/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:47:14 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 14:47:14 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	num_checker(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	safe_atoi(const char *str, int *out)
{
	long	sign;
	long	val;
	int		i;

	sign = 1;
	val = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		val = val * 10 + (str[i++] - '0');
		if (sign * val > 2147483647L || sign * val < -2147483648L)
			return (0);
	}
	*out = (int)(sign * val);
	return (1);
}

static int	has_duplicate(list *a, int v)
{
	node	*c;

	c = a->head;
	while (c)
	{
		if (c->value == v)
			return (1);
		c = c->next;
	}
	return (0);
}

list	*str_to_list(char **args, int argc, list *a)
{
	int	i;
	int	v;

	i = 0;
	while (i < argc)
	{
		if (!safe_atoi(args[i], &v) || has_duplicate(a, v))
			return (NULL);
		if (add_back(a, v) == NULL)
			return (NULL);
		i++;
	}
	return (a);
}
