/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:15:53 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/27 14:33:56 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Create a copy of a single line from the stored lines. A line is either from
// the beginning of storage until the first newline or until the end of it if 
// there is no newline
char	*dup_line(char **storage, int *storagesize, int linesize)
{
	int		i;
	char	*line;

	line = (char *) malloc(sizeof(char) * (linesize + 1));
	if (!line)
		return (0);
	i = 0;
	while (i < *storagesize && (*storage)[i] != '\n')
	{
		line[i] = (*storage)[i];
		i++;
	}
	if (has_newline(storage, storagesize))
	{
		line[i] = '\n';
		line[i + 1] = 0;
	}
	else
		line[i] = 0;
	return (line);
}

// Delete the first line from storage by allocating a new storage and copying
// everything else into it
int	del_line(char **storage, int *storagesize, int linesize)
{
	char	*newstorage;
	int		new_stor_size;

	newstorage = (char *) malloc(sizeof(char) * (*storagesize - linesize));
	if (!newstorage)
	{
		cleanup(storage, storagesize);
		return (0);
	}
	new_stor_size = *storagesize - linesize;
	ft_memcpy(newstorage, &(*storage)[linesize], *storagesize - linesize);
	*storagesize = new_stor_size;
	free(*storage);
	*storage = newstorage;
	return (1);
}

int	read_more(int fd, char **storage, int *storagesize)
{
	char	*buf;
	ssize_t	readsize;

	buf = (char *) malloc(BUFFER_SIZE);
	if (!buf)
		return (-1);
	readsize = read(fd, buf, BUFFER_SIZE);
	if (readsize < 1)
	{
		free(buf);
		return (readsize);
	}
	if (put_in_storage(storage, storagesize, buf, readsize))
	{
		free(buf);
		return (readsize);
	}
	return (-1);
}

// this calls read_more() until there is a newline in the storage or read()
// returns 0 bytes read (or -1 for fail)
int	line_mgr(char **storage, int *storagesize, int fd)
{
	int		readsize;

	readsize = 0;
	while (!has_newline(storage, storagesize))
	{
		readsize = read_more(fd, storage, storagesize);
		if (readsize == -1)
		{
			cleanup(storage, storagesize);
			return (0);
		}
		if (readsize == 0)
			break ;
	}
	if (*storagesize == 0)
	{
		cleanup(storage, storagesize);
		return (0);
	}
	return (1);
}

// Storage is a double pointer so that we can replace the inner pointer 
// with a new version in put_in_storage()
char	*get_next_line(int fd)
{
	static char	*storage = 0;
	static int	storagesize = 0;
	int			linesize;
	char		*line;

	if (!line_mgr(&storage, &storagesize, fd))
		return (0);
	linesize = get_linelen(&storage, &storagesize);
	if (linesize == 0)
	{
		cleanup(&storage, &storagesize);
		return (0);
	}
	line = dup_line(&storage, &storagesize, linesize);
	if (!line)
	{
		cleanup(&storage, &storagesize);
		return (0);
	}
	if (!del_line(&storage, &storagesize, linesize))
	{
		free(line);
		return (0);
	}
	return (line);
}
