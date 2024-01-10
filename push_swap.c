/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:04:57 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/26 15:46:43 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 1 || check_sorted(*stack_a))
		return ;
	else if (size <= 3)
		sort_small(stack_a);
	else if (size <= 5)
		sort_medium(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
	check_order(stack_a);
}

void	sort_small(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*highest;

	highest = find_big_num(stack);
	last = stack_last(*stack);
	if (last == highest)
		rotate(stack, "a");
	else if (last->prev == highest)
		reverse_rotate(stack, "a");
	last = stack_last(*stack);
	if (last->prev && last->value > last->prev->value)
		swap(stack, "a");
}

void	sort_medium(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*small;
	t_stack_node	*last;
	
	small = find_small_num(stack_a);
	while (stack_size(*stack_a) > 3)
	{
		set_index(stack_a);
		last = stack_last(*stack_a);
		if (last == small)
		{
			push(stack_b, stack_a, "b");
			small = find_small_num(stack_a);
		}
		else if (small->above_below > 0)
			rotate(stack_a, "a");
		else
			reverse_rotate(stack_a, "a");
	}
	sort_small(stack_a);
	last = stack_last(*stack_b);
	if (last->prev && (last->value < last->prev->value))
		swap(stack_b, "b");
	push(stack_a, stack_b, "a");
	push(stack_a, stack_b, "a");
}

void	sort_big(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheap;
	t_stack_node	*last_b;
	t_stack_node	*last_a;
	
	move_nodes(stack_a, stack_b);
	refresh_stacks(stack_a, stack_b);
	cheap = get_cheapest(stack_b);
	last_b = stack_last(*stack_b);
	last_a = stack_last(*stack_a);
	while (last_b)
	{
		if (cheap->above_below >= 0 && cheap->target->above_below >= 0)
			rotate_till_first(&last_a, &last_b, cheap);
		else if (cheap->above_below < 0 && cheap->target->above_below < 0)
			rev_rotate_till_first(&last_a, &last_b, cheap);
		check_single_rotations(&last_b, cheap, "b");
		check_single_rotations(&last_a, cheap->target, "a");
		push(stack_a, stack_b, "a");
		refresh_stacks(stack_a, stack_b);
		cheap = get_cheapest(stack_b);
		last_b = stack_last(*stack_b);
		last_a = stack_last(*stack_a);
	}
}

void	check_order(t_stack_node **stack)
{
	t_stack_node *small;

	set_index(stack);
	small = find_small_num(stack);
	while (small != stack_last(*stack))
		check_above_below(small, *stack, "a");
}