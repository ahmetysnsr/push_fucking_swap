/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:24:20 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 15:24:20 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>

typedef struct s_node {
	int	value;
	struct s_node *next;
	struct s_node *prev;
} node;

typedef struct s_list {
	node	*head;
	node	*tail;
	int		size;
} list;

list	*create_list_with_value(int value);
list	*create_list(void);
list	*remove_front(list *lst);
list	*remove_back(list *lst);
node	*add_front(list *lst, int value);
node	*add_back(list *lst, int value);
void	print_list_from_head(list *lst);
void	print_list_from_tail(list *lst);
void	delete_list(list *lst);
void	push(list *src, list *dst);
void	swap(list *lst);
void	rotate(list *lst);
void	reverse_rotate(list *lst);
void    do_indexing(list *stack_a);
void	pa(list *a, list *b);
void	pb(list *a, list *b);
void	ra(list *a);
void	rra(list *a);
void	sa(list *a);
void	sb(list *b);
void	ss(list *a, list *b);
void	rb(list *b);
void	rr(list *a, list *b);
void	rrb(list *b);
void	rrr(list *a, list *b);
int		list_checker(list *lst);
int		is_sorted(list *a);
void	radix_sort(list *a, list *b);
int		num_checker(char *str);
list	*str_to_list(char **args, int argc, list *a);

#endif
