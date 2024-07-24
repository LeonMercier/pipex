/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:18:33 by lemercie          #+#    #+#             */
/*   Updated: 2024/04/26 09:55:40 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	return (result);
}
