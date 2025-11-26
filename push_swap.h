/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:05:39 by asari             #+#    #+#             */
/*   Updated: 2025/11/26 18:05:39 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_list;

t_list	*create_list_with_value(int value);
t_list	*create_list(void);
t_list	*remove_front(t_list *lst);
t_list	*remove_back(t_list *lst);
t_node	*add_front(t_list *lst, int value);
t_node	*add_back(t_list *lst, int value);
void	print_list_from_head(t_list *lst);
void	print_list_from_tail(t_list *lst);
void	delete_list(t_list *lst);
void	push(t_list *src, t_list *dst);
void	swap(t_list *lst);
void	rotate(t_list *lst);
void	reverse_rotate(t_list *lst);
void	do_indexing(t_list *stack_a);
void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);
void	ra(t_list *a);
void	rra(t_list *a);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);
int		list_checker(t_list *lst);
int		is_sorted(t_list *a);
void	radix_sort(t_list *a, t_list *b);
int		num_checker(char *str);
t_list	*str_to_list(char **args, int argc, t_list *a);

#endif