/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:05:46 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/25 10:52:23 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_permitted(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n' || c == '-' || c == '+'));
}

int	check_forbidden(char *str)
{
	int	count;
	int	empty;

	empty = 1;
	count = 0;
	while (str[count])
	{
		if (ft_isdigit(str[count]))
			empty = 0;
		if ((!ft_isdigit(str[count]) && !is_permitted(str[count])
				&& ft_isascii(str[count])))
			return (0);
		if ((str[count] == '-' || str[count] == '+')
			&& !ft_isdigit(str[count + 1]))
			return (0);
		if (ft_isdigit(str[count]) && !ft_isdigit(str[count + 1])
			&& (str[count + 1] == '+' || str[count + 1] == '-'))
			return (0);
		count++;
	}
	if (empty)
		return (0);
	return (1);
}

char	**create_values(char **argv)
{
	char	**values;
	char	*str;
	char	*tmp;
	int		count;

	str = ft_strjoin("", argv[1]);
	if (!check_forbidden(argv[1]))
		return (free(str), NULL);
	count = 1;
	while (argv[++count])
	{
		if (!check_forbidden(argv[count]))
			return (free(str), NULL);
		tmp = str;
		str = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = str;
		str = ft_strjoin(tmp, argv[count]);
		free(tmp);
	}
	if (check_forbidden(str) == 0)
		return (free(str), NULL);
	values = ft_split(str, ' ');
	return (free(str), values);
}

void	free_all(char **strs)
{
	size_t	c;

	c = 0;
	while (strs[c] && strs[c][0])
	{
		free(strs[c]);
		c++;
	}
	free(strs);
}

void	error_out(t_stack_node *stack_a, t_stack_node *stack_b)
{
	write (2, "Error\n", 7);
	stack_clear(stack_a);
	stack_clear(stack_b);
	exit(0);
}
