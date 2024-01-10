/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:04:37 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/18 09:04:37 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	lst = stack_last(lst);
	while (lst)
	{

		lst = lst->prev;
		count++;
	}
	return (count);
}

void	stack_append(t_stack_node *lst, t_stack_node *obj)
{
	if (!lst)
		lst = obj;
	else
	{
		lst -> prev = obj;
		obj -> next = lst;
	}
}

void	stack_add_top(t_stack_node **lst, t_stack_node *obj)
{
	if (!*lst)
		*lst = obj;
	else
	{
		obj -> prev = stack_last(*lst);
		stack_last(*lst)->next = obj;
	}
}

t_stack_node	*stack_last(t_stack_node *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_stack_node	*stack_first(t_stack_node *lst)
{
	while (lst)
	{
		if (lst->prev == NULL)
			return (lst);
		lst = lst->prev;
	}
	return (NULL);
}
