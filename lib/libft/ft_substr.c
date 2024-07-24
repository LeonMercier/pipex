/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:00:14 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/07 11:47:25 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;

	result = (char *) malloc(sizeof(char) * (n + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, n + 1);
	return (result);
}

// return null if allocation fails
// in other fail cases return an empty string
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;

	if (!s)
		return (0);
	len_str = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strndup("", 0));
	if (len_str - start < len)
		return (ft_strndup(&s[start], len_str - start));
	return (ft_strndup(&s[start], len));
}
