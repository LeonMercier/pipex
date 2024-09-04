/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:17:48 by lemercie          #+#    #+#             */
/*   Updated: 2024/09/04 16:26:57 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	run_cmd1(t_files files, int pipefd[2], char **exec_args, char **envp)
{
	if (files.infile < 0)
	{
		close(files.outfile);
		close(pipefd[0]);
		close(pipefd[1]);
		free_strv(exec_args);
		exit(1);
	}
	dup2(files.infile, STDIN_FILENO);
	close(files.infile);
	close(files.outfile);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	if (exec_args)
		execve(exec_args[0], exec_args, envp);
	free_strv(exec_args);
	exit(1);
}

void	run_cmd2(t_files files, int pipefd[2], char **exec_args, char **envp)
{
	if (files.outfile > -1)
	{
		dup2(files.outfile, STDOUT_FILENO);
		close(files.infile);
		close(files.outfile);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		if (exec_args)
			execve(exec_args[0], exec_args, envp);
	}
	close_all(files, pipefd);
	free_strv(exec_args);
	exit(1);
}

int	wait_pids(int pid1, int pid2)
{
	int	cmd2_exitstatus;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &cmd2_exitstatus, 0);
	if (WIFEXITED(cmd2_exitstatus))
		return (WEXITSTATUS(cmd2_exitstatus));
	return (0);
}

// return value of fork() is 0 in the child and the actual pid in the parent
//
// first execve argument is the path to the binary, second is the arguments 
// BUT the first argument should also be the path to the binary
//
// execve replaces the current process with the program to be executed,
// therefore, the child will not run any code below the execve lines
//
// Seems that execve() fails cleanly if exec_args is null
//
int	piper(t_files files, char **exec_args1, char **exec_args2, char **envp)
{
	int	pid1;
	int	pid2;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (4);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		free_strv(exec_args2);
		run_cmd1(files, pipefd, exec_args1, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0)
	{
		free_strv(exec_args1);
		run_cmd2(files, pipefd, exec_args2, envp);
	}
	close_all(files, pipefd);
	return (wait_pids(pid1, pid2));
}

// zsh if cmd is an emtty string ==> permission denied
int	main(int argc, char **argv, char **envp)
{
	t_files	files;
	char	**exec_args1;
	char	**exec_args2;
	int		retval;

	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	open_files(&files, argv[1], argv[4]);
	exec_args1 = get_exec_path(argv[2], envp);
	exec_args2 = get_exec_path(argv[3], envp);
	retval = piper(files, exec_args1, exec_args2, envp);
	if (retval > 1)
		error_piper(&retval);
	if (!exec_args2)
		retval = 127;
	free_strv(exec_args1);
	free_strv(exec_args2);
	return (retval);
}
