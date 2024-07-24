/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:50:59 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/27 14:39:22 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	len_int(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_helper(char *s, long int n, int len_str, int negative)
{
	while (n > 0 && len_str > 0)
	{
		s[len_str - 1] = (n % 10) + '0';
		n = n / 10;
		len_str--;
	}
	if (negative && len_str > 0)
		s[len_str - 1] = '-';
}

char	*ft_itoa_long(long int n)
{
	int		len_str;
	int		negative;
	char	*result;

	len_str = len_int(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	result = (char *) malloc(sizeof(char) * (len_str + 1));
	if (!result)
		return (0);
	result[len_str] = '\0';
	ft_itoa_helper(result, n, len_str, negative);
	return (result);
}
