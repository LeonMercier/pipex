/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:17:49 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/03 17:07:17 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// expected behaviour is to segfault if either dst or src is null but to return
// null if both are null
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmpdst;
	char	*tmpsrc;

	if (!dst && !src)
		return (0);
	tmpdst = (char *) dst;
	tmpsrc = (char *) src;
	while (n > 0)
	{
		*tmpdst = *tmpsrc;
		tmpdst++;
		tmpsrc++;
		n--;
	}
	return (dst);
}
