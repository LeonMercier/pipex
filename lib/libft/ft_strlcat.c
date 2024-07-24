/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:24:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 19:31:02 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// system function behaviour:
// dst is NULL and dstsize > 0: segfault
// dst is NULL and dstsize == 0: return srclen 
// src is null: segfault
// for return value:
// for some reason we want to return dstsize + srclen when dstsize is smaller 
// than the actual length of the string in dst
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (dstsize < 1)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	dst += dstlen;
	i = 0;
	while (*src && i < dstsize - dstlen - 1)
	{
		*dst = *src;
		i++;
		dst++;
		src++;
	}
	if (dstlen < dstsize)
		*dst = '\0';
	return (dstlen + srclen);
}
