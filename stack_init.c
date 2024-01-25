/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:04:17 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/18 09:04:17 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*stack_init(char **values)
{
	long long		i;
	t_stack_node	*stack_a;
	t_int			val;

	i = 0;
	if (!values[0][0] || !values)
		return (NULL);
	val = ft_atoi(values[i]);
	stack_a = stack_new_node(val.value, NULL);
	if (!valid_type(val))
		return (stack_clear(stack_a), NULL);
	while (values[++i] && values[i][0])
	{
		val = ft_atoi(values[i]);
		stack_append(stack_a, stack_new_node(val.value,
				stack_a));
		stack_a = stack_a -> prev;
		if (!valid_type(val))
			return (stack_clear(stack_a), NULL);
	}
	if (!valid_dup(stack_a))
		return (stack_clear(stack_a), NULL);
	return (stack_a);
}

int	valid_type(t_int num)
{
	return (num.validity > 0);
}

t_stack_node	*valid_dup(t_stack_node *lst)
{
	t_stack_node	*tmp;

	lst = stack_first(lst);
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->value == tmp->value)
				return (NULL);
			tmp = tmp->next;
		}
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	refresh_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target(stack_b, stack_a);
	set_cost(*stack_a, *stack_b);
}
