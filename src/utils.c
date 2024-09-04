/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:57:01 by lemercie          #+#    #+#             */
/*   Updated: 2024/09/04 12:15:39 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
