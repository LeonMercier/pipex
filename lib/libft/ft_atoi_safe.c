/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:16:46 by lemercie          #+#    #+#             */
/*   Updated: 2024/07/03 11:34:38 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	has_garbage(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

static int	ft_atoi_loop(const char *str, int negative, int *err_atoi)
{
	unsigned int	temp;
	unsigned int	result;
	unsigned int	one_over_max;

	temp = 0;
	result = 0;
	one_over_max = INT_MAX;
	one_over_max++;
	while (ft_isdigit(*str))
	{
		temp = (temp * 10) + (*str++ - '0');
		if (temp / 10 != result && negative)
			*err_atoi = 1;
		if (temp / 10 != result && !negative)
			*err_atoi = 1;
		if ((!negative && temp > INT_MAX) || (negative && temp > one_over_max))
			*err_atoi = 1;
		if (*err_atoi)
			return (0);
		result = temp;
	}
	if (negative)
		return ((int) -result);
	else
		return ((int) result);
}

int	ft_atoi_safe(const char *str, int *err_atoi)
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
	if (has_garbage(str))
	{
		*err_atoi = 1;
		return (0);
	}
	return (ft_atoi_loop(str, negative, err_atoi));
}
