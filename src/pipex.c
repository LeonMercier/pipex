/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:17:48 by lemercie          #+#    #+#             */
/*   Updated: 2024/08/21 16:48:05 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// return value of fork() is 0 in the child and the actual pid in the parent
//
// first execve argument is the path to the binary, second is the arguments 
// BUT the first argument should also be the path to the binary
int	piper(char **argv, char **envp)
{
	int		pid1;
	int		pid2;
	char	**cmd1;
	char	**cmd2;
	int		pipefd[2];
	
	if (pipe(pipefd) == -1)
	{
		ft_printf("Error: pipe() failed\n");
		return (1);
	}
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	pid1 = fork();
	if (pid1 < 0)
	{
		ft_printf("Error: fork() failed\n");
		return (1);
	}
	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(cmd1[0], cmd1, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		ft_printf("Error: fork() failed\n");
		return (1);
	}
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(cmd2[0], cmd2, envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

char	**get_paths(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			return (ft_split(*envp, ':'));
		}
		else
			envp++;
	}
	ft_printf("Error int get_paths(); PATH not found in envp\n");
	return (NULL);
}

char	*get_exec_path(char *command, char **envp)
{
	char	**paths;
	char	*exec_name;
	char	*exec_path;	
	int		exec_path_len;

	exec_name = ft_split(command, ' ')[0];
	paths = get_paths(envp);
	while (*paths)
	{
		exec_path_len = ft_strlen(*paths) + ft_strlen(exec_name) + 2;
		exec_path = malloc(sizeof(char) * exec_path_len);
		ft_strlcat(exec_path, *paths, exec_path_len);
		ft_strlcat(exec_path, "/", exec_path_len);
		ft_strlcat(exec_path, exec_name, exec_path_len);
		if (access(exec_path, X_OK) == 0)
			return (exec_path);
		paths++;
	}
	ft_printf("Error in get_exec_path; executable not found or not accessible\n");
	return (NULL);
}

 // handle file opening before forking
int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	char	*exec_path1;
	char	*exec_path2;
	
	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		ft_printf("Error: failed to open infile\n");
		return (1);
	}
	outfile = open(argv[4], O_WRONLY | O_CREAT);
	if (outfile < 0)
	{
		ft_printf("Error: failed to open outfile\n");
		return (1);
	}
	exec_path1 = get_exec_path(argv[2], envp);
	exec_path2 = get_exec_path(argv[3], envp);
	return (piper(argv, envp));
}








