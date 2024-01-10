/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:10:16 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/25 11:10:16 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_big_num(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*biggest;

	node = stack_first(*stack);
	biggest = node;
	while (node)
	{
		if (biggest->value < node->value)
			biggest = node;
		node = node->next;
	}
	return (biggest);
}

t_stack_node	*find_small_num(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*smallest;

	node = stack_first(*stack);
	smallest = node;
	while (node)
	{
		if (smallest->value > node->value)
			smallest = node;
		node = node->next;
	}
	return (smallest);
}

void	set_target(t_stack_node **stack, t_stack_node **target_stack)
{
	t_stack_node	*node;
	t_stack_node	*look_node;
	t_stack_node	*target_node;
	long			next_big;

	node = stack_last(*stack);
	while (node)
	{
		next_big = LONG_MAX;
		look_node = stack_last(*target_stack);
		while (look_node)
		{
			if (look_node->value > node->value && look_node->value < next_big)
			{
				next_big = look_node->value;
				target_node = look_node;
			}
			look_node = look_node->prev;
		}
		if (next_big == LONG_MAX)
			node->target = find_small_num(target_stack);
		else
			node->target = target_node;
		node = node->prev;
	}
}

void	set_index(t_stack_node **stack)
{
	t_stack_node	*node;
	int				count;
	int				len;

	len = stack_size(*stack);
	node = stack_last(*stack);
	count = 0;
	while (node)
	{
		node->index = count;
		if (count <= (len / 2))
			node->above_below = 1;
		else
			node->above_below = -1;
		node = node->prev;
		count++;
	}
}

void	set_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	a_len;
	int	b_len;

	a_len = stack_size(stack_a);
	b_len = stack_size(stack_b);
	stack_b = stack_last(stack_b);
	while (stack_b)
	{
		stack_b->target_cost = stack_b->index;
		if (stack_b->target_cost > (b_len / 2))
			stack_b->target_cost = b_len - stack_b->target_cost;
		if (stack_b->target->index > (a_len / 2))
			stack_b->target_cost += a_len - stack_b->target->index;
		else
			stack_b->target_cost += stack_b->target->index;
		stack_b = stack_b->prev;
	}
}
