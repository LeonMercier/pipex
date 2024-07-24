/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:44:45 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/07 11:49:44 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t len)
{
	char	*dst;
	int		i;

	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (len > 0)
	{
		dst[i] = *s1;
		i++;
		s1++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i_start;
	int	i_end;

	if (!s1 || !set)
		return (0);
	if (ft_strlen(s1) == 0)
		return (ft_strndup("", 0));
	if (ft_strlen(set) == 0)
		return (ft_strndup(s1, ft_strlen(s1)));
	i_start = 0;
	while (ft_strchr(set, s1[i_start]))
	{
		i_start++;
	}
	i_end = (int) ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i_end]))
	{
		i_end--;
		if (i_end < 1)
			return (ft_strndup("", 0));
	}
	return (ft_strndup(&s1[i_start], (i_end - i_start) + 1));
}
