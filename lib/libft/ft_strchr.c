/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:10:58 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/06 19:35:30 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// system function behaviour: segfault on null pointer argument
// casting c to char means small overflows are correctly wrapped around
// c-=256 handles large overflows
char	*ft_strchr(const char *s, int c)
{
	char	cc;

	while (c >= 256)
		c -= 256;
	cc = (char) c;
	while (*s)
	{
		if (*s == cc)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *) s);
	return (0);
}
