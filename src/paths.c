/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon </var/spool/mail/leon>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:13:05 by leon              #+#    #+#             */
/*   Updated: 2024/09/04 16:52:45 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**get_paths(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			return (ft_split(*envp, ':'));
		}
		envp++;
	}
	return (NULL);
}

static char	*create_path(char *dir, char *cmd)
{
	int		exec_path_len;
	char	*exec_path;

	exec_path_len = ft_strlen(dir) + ft_strlen(cmd) + 2;
	exec_path = malloc(sizeof(char) * exec_path_len);
	if (!exec_path)
		return (NULL);
	ft_strlcpy(exec_path, dir, exec_path_len);
	ft_strlcat(exec_path, "/", exec_path_len);
	ft_strlcat(exec_path, cmd, exec_path_len);
	return (exec_path);
}

static int	find_in_paths(char **paths, char **exec_args)
{
	char	*exec_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		exec_path = create_path(paths[i], exec_args[0]);
		if (!exec_path)
			return (1);
		if (access(exec_path, X_OK) == 0)
		{
			free(exec_args[0]);
			free_strv(paths);
			exec_args[0] = exec_path;
			return (0);
		}
		free(exec_path);
		i++;
	}
	return (1);
}

char	**get_exec_path(char *command, char **envp)
{
	char	**paths;
	char	**exec_args;

	exec_args = ft_split(command, ' ');
	if (!exec_args || !exec_args[0])
		return (NULL);
	if (access(exec_args[0], X_OK) == 0)
		return (exec_args);
	paths = get_paths(envp);
	if (!paths)
	{
		print_error("Command not found", exec_args[0]);
		free_strv(exec_args);
		return (NULL);
	}
	if (find_in_paths(paths, exec_args))
	{
		print_error("Command not found", exec_args[0]);
		free_strv(exec_args);
		free_strv(paths);
		return (NULL);
	}
	return (exec_args);
}
