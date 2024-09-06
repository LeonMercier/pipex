/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:57:01 by lemercie          #+#    #+#             */
/*   Updated: 2024/09/06 18:18:23 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	check_exec_access(char *cmd, int *path_error)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (0);
		*path_error = 126;
		return (2);
	}
	return (1);
}

int	open_files(t_files *files, char *infile_name, char *outfile_name)
{
	files->infile = open(infile_name, O_RDONLY);
	if (files->infile < 0)
		print_error(strerror(errno), infile_name);
	files->outfile = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (files->outfile < 0)
	{
		print_error(strerror(errno), outfile_name);
	}
	return (0);
}

void	close_all(t_files files, int pipefd[2])
{
	if (files.infile > -1)
		close(files.infile);
	if (files.outfile > -1)
		close(files.outfile);
	close(pipefd[0]);
	close(pipefd[1]);
}

void	print_error(char *message, char *filename)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("\n", 2);
}

void	free_strv(char **strv)
{
	int	i;

	if (strv)
	{
		i = 0;
		while (strv[i])
		{
			free(strv[i]);
			i++;
		}
		free(strv);
	}
}
