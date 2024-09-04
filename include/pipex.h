/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:21:10 by lemercie          #+#    #+#             */
/*   Updated: 2024/09/04 12:15:52 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h> // dup2(), access(), execve()
# include <sys/wait.h> // waitpid()
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h> // strerror
# include <stdio.h> // perror()
# include <errno.h> //perror ()
# include "../lib/libft/libft.h"
typedef struct s_files
{
	int	infile;
	int	outfile;
} t_files;
// paths.c
char	**get_paths(char **envp);
char	**get_exec_path(char *command, char **envp);
// utils.c
void	print_error(char *message, char *filename);
void	free_strv(char **strv);
#endif

