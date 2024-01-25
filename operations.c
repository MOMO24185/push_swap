/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:19:01 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/26 14:19:01 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pa
//push a (pops first element at stack b and puts it at the top of stack a)
//does nothing if stack b is empty
//pb
//push b (pops first element at stack a and puts it at the top of stack b)
//does nothing if stack a is empty

void	push(t_stack_node **stack_a, t_stack_node **stack_b, char *str)
{
	t_stack_node	*node_a;
	t_stack_node	*new;
	t_stack_node	*node_b;

	node_b = stack_last(*stack_b);
	if (!node_b)
		return ;
	node_a = stack_last(*stack_a);
	ft_putstr_fd("p", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	new = node_b;
	node_b = node_b->prev;
	if (node_b)
		node_b->next = NULL;
	*stack_b = node_b;
	if (node_a)
	{
		node_a->next = new;
		*stack_a = new;
	}
	else
		*stack_a = new;
	new->prev = node_a;
}

//sa
//Swap a (swaps the first 2 elements at the top of stack a)
//does nothing if there is 1 or no elements
//sb
//Swap b (swaps the first 2 elements at the top of stack b)
//does nothing if there is 1 or no elements
//ss
//Swaps using sa and sb at the same time
//does nothing if there is 1 or no elements

void	swap(t_stack_node **node, char *str)
{
	t_stack_node	*target;
	t_stack_node	*node_prev;
	t_stack_node	*node_prev_prev;

	target = stack_last(*node);
	if (!target && !target->prev)
		return ;
	ft_putstr_fd("s", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	node_prev_prev = target->prev->prev;
	node_prev = target->prev;
	node_prev->prev = target;
	node_prev->next = NULL;
	target->next = node_prev;
	if (node_prev_prev)
	{
		target->prev = node_prev_prev;
		node_prev_prev->next = target;
	}
	else
		target->prev = NULL;
}

void	rotate(t_stack_node **stack, char *str)
{
	t_stack_node	*bottom;
	t_stack_node	*top;

	if (!(*stack) || stack_size(*stack) < 2)
		return ;
	if (str != 0)
	{
		ft_putstr_fd("r", 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	bottom = stack_first(*stack);
	top = stack_last(*stack);
	top->prev->next = NULL;
	top->next = bottom;
	top->prev = NULL;
	bottom->prev = top;
}

void	reverse_rotate(t_stack_node **stack, char *str)
{
	t_stack_node	*bottom;
	t_stack_node	*top;

	if (!(*stack) || stack_size(*stack) < 2)
		return ;
	if (str != 0)
	{
		ft_putstr_fd("rr", 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	bottom = stack_first(*stack);
	top = stack_last(*stack);
	top->next = bottom;
	bottom->next->prev = NULL;
	bottom->next = NULL;
	bottom->prev = top;
}
