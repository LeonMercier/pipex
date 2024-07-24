/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:03:13 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/27 14:41:15 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*handle_string(char *s)
{
	if (s)
		return (ft_strdup(s));
	else
		return (ft_strdup("(null)"));
}

char	*handle_voidptr(void *ptr)
{
	char	*str;
	char	*hex;

	if (ptr)
	{
		hex = handle_hex((uintptr_t) ptr, 0);
		str = ft_strjoin("0x", hex);
		free(hex);
		return (str);
	}
	else
		return (ft_strdup("0x0"));
}

char	*handle_int(int n)
{
	return (ft_itoa(n));
}

char	*handle_uint(unsigned int n)
{
	return (ft_itoa_long(n));
}
