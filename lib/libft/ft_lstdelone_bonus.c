/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:36:38 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/07 11:53:53 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// we just free the node and let the list break
void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (lst && del)
	{
		if (lst->content)
			del(lst->content);
		free(lst);
	}
}
