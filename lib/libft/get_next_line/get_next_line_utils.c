/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:50:53 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/27 14:34:14 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmpdst;
	char	*tmpsrc;

	if (!dst && !src)
		return (0);
	tmpdst = (char *) dst;
	tmpsrc = (char *) src;
	while (n > 0)
	{
		*tmpdst = *tmpsrc;
		tmpdst++;
		tmpsrc++;
		n--;
	}
	return (dst);
}

void	cleanup(char **storage, int *storagesize)
{
	if (*storage)
	{
		free(*storage);
		*storage = 0;
	}
	*storagesize = 0;
}

int	has_newline(char **storage, int *storagesize)
{
	int	i;

	if (!(*storage))
		return (0);
	i = 0;
	while (i < *storagesize)
	{
		if ((*storage)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_linelen(char **storage, int	*storagesize)
{
	int	len;

	if (!(*storage))
		return (0);
	len = 0;
	while (len < *storagesize && (*storage)[len] != '\n')
	{
		len++;
	}
	if (has_newline(storage, storagesize))
		len++;
	return (len);
}

// If storage already exists, we copy its contents to newstorage and append 
// the read buffer to that
// else, we just copy the read buffer to a new storage
int	put_in_storage(char **storage, int *storagesize, char *buf, int readsize)
{
	char	*newstorage;

	newstorage = (char *) malloc(sizeof(char) * (*storagesize + readsize));
	if (!newstorage)
	{
		free(buf);
		cleanup(storage, storagesize);
		return (0);
	}
	if (*storage)
		ft_memcpy(newstorage, *storage, *storagesize);
	ft_memcpy(&newstorage[*storagesize], buf, readsize);
	if (*storage)
		free(*storage);
	*storagesize += readsize;
	*storage = newstorage;
	return (1);
}
