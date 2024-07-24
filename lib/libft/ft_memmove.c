/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:23:32 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 18:11:24 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// system function returns null if both src and dest are null, but segfaults
// if onlly one of them is null
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmpdst;
	char	*tmpsrc;

	if (!dst && !src)
		return (0);
	tmpdst = (char *) dst;
	tmpsrc = (char *) src;
	if (tmpdst > tmpsrc)
	{
		while (len > 0)
		{
			tmpdst[len - 1] = tmpsrc[len - 1];
			len--;
		}
	}
	else
	{
		while (len-- > 0)
		{
			*tmpdst = *tmpsrc;
			tmpdst++;
			tmpsrc++;
		}
	}
	return (dst);
}
