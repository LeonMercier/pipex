/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:16:46 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/07 15:55:47 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi_loop(const char *str, int negative)
{
	long	temp;
	long	result;

	temp = 0;
	result = 0;
	while (ft_isdigit(*str))
	{
		temp = (temp * 10) + (*str++ - '0');
		if (temp / 10 != result && negative)
			return (0);
		if (temp / 10 != result && !negative)
			return (-1);
		result = temp;
	}
	if (negative)
		return ((int) -result);
	else
		return ((int) result);
}

// expected behaviour: any amount of whitespace, then optionally a singular +
//  or - then digits. Garbage after the digits end is tolerated.
//
//  system function segfaults on null pointer argument
//  this function behaves the same whether n is declared as long long or int
int	ft_atoi(const char *str)
{
	int		negative;

	negative = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (!ft_isdigit(*str))
	{
		if (*str == '-')
			negative = 1;
		else if (*str != '+')
			return (0);
		str++;
	}
	return (ft_atoi_loop(str, negative));
}
