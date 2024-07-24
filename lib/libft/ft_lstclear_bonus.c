/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:26:51 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/07 12:00:15 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	if (!lst || !*lst || !del)
		return ;
	if ((*lst)->next)
	{
		ft_lstclear(&(*lst)->next, del);
	}
	ft_lstdelone(*lst, del);
	*lst = 0;
}
