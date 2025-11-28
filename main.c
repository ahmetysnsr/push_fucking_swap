/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:20:08 by asari             #+#    #+#             */
/*   Updated: 2025/11/28 13:04:17 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **args)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = create_list();
	b = create_list();
	if (argc == 2)
	{
		if (single_arg_to_list(a, args[1]) == 0)
		{
			delete_list(a);
			delete_list(b);
			return (error());
		}
	}
	else
	{
		if (str_to_list(&args[1], argc - 1, a) == NULL)
		{
			delete_list(a);
			delete_list(b);
			return (error());
		}
	}
	if (is_sorted(a))
	{
		delete_list(a);
		delete_list(b);
		return (0);
	}
	if (do_indexing(a) == 0)
	{
		delete_list(a);
		delete_list(b);
		return (error());
	}
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
	delete_list(a);
	delete_list(b);
	return (0);
}
