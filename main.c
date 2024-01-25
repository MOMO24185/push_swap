/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:56:35 by melshafi          #+#    #+#             */
/*   Updated: 2023/12/18 08:56:35 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Main push_swap program
int	main(int argc, char **argv)
{
	char			**values;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	values = NULL;
	if (argc <= 1)
		return (0);
	else
		values = create_values(argv);
	if (!values)
		error_out(NULL, NULL);
	stack_a = stack_init(values);
	stack_b = NULL;
	free_all(values);
	if (stack_a == NULL)
		error_out(stack_a, stack_b);
	push_swap(&stack_a, &stack_b);
	return (stack_clear(stack_a), stack_clear(stack_b), 1);
}
