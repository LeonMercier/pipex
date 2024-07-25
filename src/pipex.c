/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:17:48 by lemercie          #+#    #+#             */
/*   Updated: 2024/07/25 17:29:27 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	piper(int *pipefd, char **argv, char **envp)
{
	int		pid1;
	int		pid2;
	char	**cmd1;
	char	**cmd2;
	
	cmd1 = ft_split(argv[1], ' ');
	cmd2 = ft_split(argv[2], ' ');
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


// return value of fork() is 0 in the child and the actual pid in the parent
//
// first execve argument is the path to the binary, second is the arguments 
// BUT the first argument should also be the path to the binary
int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
		if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (pipe(pipefd) == -1)
		return (1);
	return (piper(pipefd, argv, envp));
}








