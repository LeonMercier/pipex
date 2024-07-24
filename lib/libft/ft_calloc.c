/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:56 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/03 16:00:40 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// SIZE_MAX / count gives the maximum size of an individual element
// if the size passed to the function is larger than that, we fail
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && SIZE_MAX / count < size)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
