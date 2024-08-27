/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:57:01 by lemercie          #+#    #+#             */
/*   Updated: 2024/08/27 16:23:16 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
