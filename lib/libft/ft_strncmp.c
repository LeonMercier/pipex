/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:46:13 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 19:48:34 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// system function behaviour:
// if n == 0, return 0
// if there is a NULL pointer and n != 0, segfault
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	us1;
	unsigned char	us2;

	while (n > 0 && *s1 && *s2)
	{
		us1 = (unsigned char) *s1;
		us2 = (unsigned char) *s2;
		if (us1 != us2)
			return (us1 - us2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	if (*s1)
		return (1);
	else if (*s2)
		return (-1);
	else
		return (0);
}
