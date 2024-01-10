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

//Debugging functions
char	**create_values(char **argv);
void	print_stacks(t_stack_node *stack_a, t_stack_node *stack_b);
void	test_op(t_stack_node *stack_a, t_stack_node *stack_b);
void	print_stack(t_stack_node *stack);

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

//Debugging functions
void	print_stack(t_stack_node *stack)
{
	t_stack_node	*node;

	node = stack_last(stack);
	printf("\n");
	while (node)
	{
		printf("%d\n", node->value);
		node = node->prev;
	}
	printf("-\na\n\n");
}

void	print_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int				count = -1;
	int				a;
	int				b;
	t_stack_node	*node_a;
	t_stack_node	*node_b;

	a = stack_size(stack_a);
	b = stack_size(stack_b);
	node_a = stack_last(stack_a);
	node_b = stack_last(stack_b);
	while (++count < a)
	{
		if (node_a)
		{
			printf("%d	", node_a->value);
			node_a = node_a->prev;
		}
		printf("\n");
	}
	printf("-\na\n---------------------------\n");
	count = -1;
	while (++count < b)
	{
		if (node_b)
		{
			printf("%d	", node_b->value);
			node_b = node_b->prev;
		}
		printf("\n");
	}
	printf("-\nb\n");
}

//Testing function to ensure operations work successfully
int	ft_strcmp(char *s1, char *s2)
{
	int		count;

	count = 0;
	while (s1[count] && s2[count])
	{
		if (s1[count] != s2[count])
			return (0);
		count++;
	}
	return (1);
}

void	check_operations(char *str, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_strcmp(str, "sa") == 1)
		swap(stack_a, "sa\n");
	else if (ft_strcmp(str, "sb") == 1)
		swap(stack_b, "sb\n");
	else if (ft_strcmp(str, "ss") == 1)
	{
		swap(stack_a, "ss\n");
		swap(stack_b, "");
	}
	else if (ft_strcmp(str, "pa") == 1)
		push(stack_a, stack_b, "pa\n");
	else if (ft_strcmp(str, "pb") == 1)
		push(stack_b, stack_a, "pb\n");
	else if (ft_strcmp(str, "rra") == 1)
		reverse_rotate(stack_a, "rra\n");
	else if (ft_strcmp(str, "rrb") == 1)
		reverse_rotate(stack_b, "rrb\n");
	else if (ft_strcmp(str, "rrr") == 1)
	{
		reverse_rotate(stack_a, "rrr\n");
		reverse_rotate(stack_b, "");
	}
	else if (ft_strcmp(str, "ra") == 1)
		rotate(stack_a, "ra\n");
	else if (ft_strcmp(str, "rb") == 1)
		rotate(stack_b, "rb\n");
	else if (ft_strcmp(str, "rr") == 1)
	{
		rotate(stack_a, "rr\n");
		rotate(stack_b, "");
	}
	else
		return ;
}

void	test_op(t_stack_node *stack_a, t_stack_node *stack_b)
{
	char	input[255];

	print_stacks(stack_a, stack_b);
	printf("Please enter an operation:\n");
	scanf("%s", input);
	while (ft_strcmp(input, "q") != 1)
	{
		check_operations(input, &stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		printf("Please enter an operation:\n");
		scanf("%s", input);
	}
}
