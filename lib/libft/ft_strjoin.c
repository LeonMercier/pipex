/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:50:30 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/07 11:49:06 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	dstsize;

	if (!s1 || !s2)
		return (0);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *) malloc(sizeof(char) * dstsize);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, dstsize);
	ft_strlcpy(&result[ft_strlen(s1)], s2, dstsize);
	return (result);
}
