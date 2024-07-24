/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:34:22 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 20:06:10 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// system function behaviour:
// s == NULL && n > 0: segfault
// s == NULL && n == 0: return null pointer
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	chr;

	tmp_ptr = (unsigned char *) s;
	chr = (unsigned char) c;
	while (n > 0)
	{
		if (*tmp_ptr == chr)
			return ((void *) tmp_ptr);
		tmp_ptr++;
		n--;
	}
	return (0);
}
