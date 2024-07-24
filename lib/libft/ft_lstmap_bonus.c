/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:36:46 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/03 17:22:51 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lstmap_loop(t_list *head, t_list *orig_lst, void *(*f) (void *),
		void (*del) (void *))
{
	t_list	*current;
	void	*cont;

	while (orig_lst)
	{
		cont = f(orig_lst->content);
		if (!cont)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		current = ft_lstnew(cont);
		if (!current)
		{
			del(cont);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, current);
		orig_lst = orig_lst->next;
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*head;
	void	*cont;

	if (!lst || !f || !del)
		return (0);
	cont = f(lst->content);
	if (!cont)
		return (0);
	head = ft_lstnew(cont);
	if (!head)
	{
		del(cont);
		return (0);
	}
	if (ft_lstmap_loop(head, lst->next, f, del))
		return (head);
	else
		return (0);
}
