/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:46:03 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/07 12:03:50 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t len)
{
	char	*dst;
	int		i;

	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (len > 0)
	{
		dst[i] = *s1;
		i++;
		s1++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_substr_count(char const *s, char c)
{
	int	count_substr;
	int	i;
	int	instring;

	if (!s)
		return (-1);
	instring = 0;
	count_substr = 0;
	i = 0;
	while (s[i])
	{
		if (!instring && s[i] != c)
		{
			instring = 1;
			count_substr++;
		}
		else if (instring && s[i] == c)
			instring = 0;
		i++;
	}
	return (count_substr);
}

static char	**ft_free_str_array(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	ft_len_substr(char const *s, char c)
{
	int	i;

	if (!(*s))
		return (0);
	i = 1;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

// repeated delimiter SHOULD NOT result in an empty string
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		i_result;

	result = (char **) malloc(sizeof(char *) * (ft_substr_count(s, c) + 1));
	if (!result || ft_substr_count(s, c) < 0)
		return (0);
	i = 0;
	i_result = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (ft_len_substr(&s[i], c) > 0)
		{
			result[i_result++] = ft_strndup(&s[i], ft_len_substr(&s[i], c));
			if (!result[i_result - 1])
				return (ft_free_str_array(result, i_result));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	result[i_result] = 0;
	return (result);
}
