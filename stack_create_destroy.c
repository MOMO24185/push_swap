/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:04:39 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/18 09:04:39 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*stack_new_node(int value, t_stack_node	*next)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->target_cost = 0;
	node->above_below = 0;
	node->target = NULL;
	node->next = next;
	node->prev = NULL;
	return (node);
}

void	stack_delone(t_stack_node *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	stack_clear(t_stack_node *lst)
{
	t_stack_node	*del_one;
	t_stack_node	*next_one;

	if (!lst)
		return ;
	del_one = stack_last(lst);
	while (del_one)
	{
		next_one = del_one->prev;
		stack_delone(del_one);
		del_one = next_one;
	}
	lst = NULL;
}
