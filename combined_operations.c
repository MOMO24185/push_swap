/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:49:50 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/02 09:49:50 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a, "r");
	rotate(stack_b, 0);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a, "r");
	reverse_rotate(stack_b, 0);
}

void	check_single_rotations(t_stack_node **stack, t_stack_node *target,
			char *str)
{
	while (target != stack_last(*stack))
		check_above_below(target, *stack, str);
}

void	rotate_till_first(t_stack_node **stack_a, t_stack_node **stack_b,
			t_stack_node *cheap)
{
	t_stack_node	*cheap2;
	t_stack_node	*last_a;
	t_stack_node	*last_b;

	cheap2 = get_next_cheapest(stack_b, cheap->value);
	last_a = stack_last(*stack_a);
	last_b = stack_last(*stack_b);
	while (cheap->target != last_a && cheap != last_b)
	{
		if (cheap2 == cheap->next && cheap2 == last_b)
		{
			swap(stack_b, "b");
			break ;
		}
		rr(stack_a, stack_b);
		last_a = stack_last(*stack_a);
		last_b = stack_last(*stack_b);
	}
	set_index(stack_a);
	set_index(stack_b);
}

void	rev_rotate_till_first(t_stack_node **stack_a, t_stack_node **stack_b,
			t_stack_node *cheap)
{
	t_stack_node	*cheap2;
	t_stack_node	*last_a;
	t_stack_node	*last_b;

	cheap2 = get_next_cheapest(stack_b, cheap->value);
	last_a = stack_last(*stack_a);
	last_b = stack_last(*stack_b);
	while (cheap->target != last_a && cheap != last_b)
	{
		if (cheap2 == cheap->next && cheap2 == last_b)
		{
			swap(stack_b, "b");
			break ;
		}
		rrr(stack_a, stack_b);
		last_a = stack_last(*stack_a);
		last_b = stack_last(*stack_b);
	}
	set_index(stack_a);
	set_index(stack_b);
}
