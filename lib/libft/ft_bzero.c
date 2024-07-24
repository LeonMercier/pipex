/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:14:31 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 18:07:54 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// system version of the function segfaults on null pointer argument,
// hence no protection
void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *) s;
	while (n > 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
}
