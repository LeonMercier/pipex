/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:38:19 by lemercie          #+#    #+#             */
/*   Updated: 2024/09/23 15:11:58 by lemercie         ###   ########.fr       */
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

static int	find_in_paths(char **paths, char **exec_args, int *path_error)
{
	char	*exec_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		exec_path = create_path(paths[i], exec_args[0]);
		if (!exec_path)
			return (1);
		if (check_exec_access(exec_path, path_error) == 0)
		{
			free(exec_args[0]);
			free_strv(paths);
			exec_args[0] = exec_path;
			return (0);
		}
		if (check_exec_access(exec_path, path_error) == 2)
			return (1);
		free(exec_path);
		i++;
	}
	*path_error = 127;
	return (1);
}

static char	**search_paths(char **exec_args, char **envp, int *path_error)
{
	char	**paths;

	paths = get_paths(envp);
	if (!paths)
	{
		print_error("Command not found", exec_args[0]);
		free_strv(exec_args);
		return (NULL);
	}
	if (find_in_paths(paths, exec_args, path_error))
	{
		print_error("Command not found", exec_args[0]);
		free_strv(exec_args);
		free_strv(paths);
		return (NULL);
	}
	return (exec_args);
}

bool	is_abs_or_pwd_path(char *cmd)
{
	if (cmd && ft_strlen(cmd) > 1)
	{
		if (ft_strncmp(cmd, "/", 1))
			return (true);
		if (ft_strncmp(cmd, "./", 2) == 0)
			return (true);
	}
	return (false);
}

// 3 possibilities
// 		absolute path
// 		path found in PATH
// 		current dir with ./
//TODO: only search current dir if there is a ./
// if the cmd is an empty string ==> return 126
// if the cmd is a real file but not executable ==> return 127
// if the cmd is not found ==> return 127
char	**get_exec_path(char *command, char **envp, int *path_error)
{
	char	**exec_args;
	int		exec_access_error;

	exec_args = ft_split(command, ' ');
	if (!exec_args)
		return (NULL);
	if (!exec_args[0])
	{
		*path_error = 126;
		return (NULL);
	}
	if (is_abs_or_pwd_path(exec_args[0]))
	{
		exec_access_error = check_exec_access(exec_args[0], path_error);
		if (exec_access_error == 0)
			return (exec_args);
		if (exec_access_error == 2)
		{
//			print_error("Permission denied", exec_args[0]);
			print_error(strerror(errno), exec_args[0]);
			return (NULL);
		}
	}
	return (search_paths(exec_args, envp, path_error));
}
