/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:00:29 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 18:30:03 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// system function behaviour:
// if src is NULL: segfault
// if dst is NULL and dstsize is 0: return srclen
// if dst is NULL and dstsize > 0: segfault
// if dstsize == -1: abort
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize < 1)
		return (srclen);
	while (*src && dstsize - 1 > 0)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (srclen);
}
