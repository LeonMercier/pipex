/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:21:10 by lemercie          #+#    #+#             */
/*   Updated: 2024/08/30 12:25:11 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h> // dup2(), access(), execve()
# include <sys/wait.h> // waitpid()
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
typedef struct s_files
{
	int	infile;
	int	outfile;
} t_files;

void	free_strv(char **strv);
#endif

