/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:27:01 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 20:43:48 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// system function behaviour
// needle is NULL: segfault
// haystack is NULL AND size > 0: segfault
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	if (len < 1 && needle && !haystack)
		return (0);
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) > 0)
		return (0);
	if ((ft_strlen(haystack) == 0 && len < 1) || ft_strlen(needle) == 0)
		return ((char *) haystack);
	len_needle = ft_strlen(needle);
	while (*haystack && len >= len_needle)
	{
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (0);
}
