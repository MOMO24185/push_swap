/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:18:54 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/26 14:18:54 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_nodes(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (stack_size(*stack_a) > 3)
		push(stack_b, stack_a, "b");
	sort_small(stack_a);
	refresh_stacks(stack_a, stack_b);
}

t_stack_node	*get_cheapest(t_stack_node **stack)
{
	long			cheapest;
	t_stack_node	*cheap_node;
	t_stack_node	*node;

	node = stack_last(*stack);
	cheapest = LONG_MAX;
	while (node)
	{
		if (node->target_cost < cheapest)
		{
			cheapest = node->target_cost;
			cheap_node = node;
		}
		node = node->prev;
	}
	return (cheap_node);
}

t_stack_node	*get_next_cheapest(t_stack_node **stack, int current_cheapest)
{
	long			cheapest;
	t_stack_node	*cheap_node;
	t_stack_node	*node;

	node = stack_last(*stack);
	cheapest = LONG_MAX;
	while (node)
	{
		if (node->target_cost < cheapest
			&& node->target_cost > current_cheapest)
		{
			cheapest = node->target_cost;
			cheap_node = node;
		}
		node = node->prev;
	}
	return (cheap_node);
}

int	check_sorted(t_stack_node *stack)
{
	t_stack_node *last;

	last = stack_last(stack);
	while (last)
	{
		if (last->prev && last->value > last->prev->value)
			return (0);
		last = last->prev;
	}
	return (1);
}

void	check_above_below(t_stack_node *node, t_stack_node *stack, char *str)
{
	if (node->above_below >= 0)
		rotate(&stack, str);
	else
		reverse_rotate(&stack, str);
}