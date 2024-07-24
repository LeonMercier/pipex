/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:17:36 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 19:37:19 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//system function behaviour on nulll pointer argument: segfault
char	*ft_strrchr(const char *s, int c)
{
	char	*lastchr;
	char	cc;

	while (c >= 256)
		c -= 256;
	cc = (char) c;
	lastchr = 0;
	while (*s)
	{
		if (*s == cc)
			lastchr = (char *) s;
		s++;
	}
	if (c == 0)
		lastchr = (char *) s;
	return (lastchr);
}
