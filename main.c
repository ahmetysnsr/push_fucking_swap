/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:20:08 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 16:23:57 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **args)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = create_list();
	b = create_list();
	tmp = str_to_list(&args[1], argc - 1, a);
	if (tmp == NULL)
	{
		printf("Error\n");
		return (1);
	}
	do_indexing(a);
	radix_sort(a, b);
	delete_list(a);
	delete_list(b);
}
