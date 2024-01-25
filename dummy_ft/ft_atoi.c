/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshafi <melshafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:17:14 by melshafi          #+#    #+#             */
/*   Updated: 2024/01/25 10:50:51 by melshafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	allowed_chars(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

t_int	ft_atoi(const char *str)
{
	t_int				returned;
	int					count;
	long long			result;
	int					minus_sign;

	count = 0;
	result = 0;
	minus_sign = 1;
	while (allowed_chars(str[count]))
		count++;
	if (str[count] == '-')
		minus_sign *= -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		result *= 10;
		result += str[count++] - '0';
	}
	returned.value = result * minus_sign;
	returned.validity = 1;
	if (result > INT_MAX || result < INT_MIN)
		returned.validity = -1;
	return (returned);
}
