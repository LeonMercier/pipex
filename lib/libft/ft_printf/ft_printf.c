/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:50:44 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/27 14:39:10 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	put_char_buf(char **buf, int *buflen, char c)
{
	char	*newbuf;

	newbuf = (char *) malloc(sizeof(char) * (*buflen + 1));
	if (!newbuf)
	{
		free(*buf);
		*buf = 0;
		return (0);
	}
	if (buf && *buf)
		ft_memcpy(newbuf, *buf, *buflen);
	newbuf[*buflen] = c;
	*buflen = *buflen + 1;
	if (buf && *buf)
	{
		free(*buf);
	}
	*buf = newbuf;
	return (1);
}

int	put_str_buf(char **buf, int *buflen, char *str)
{
	char	*newbuf;
	int		i;

	newbuf = (char *) malloc(sizeof(char) * (*buflen + ft_strlen(str)));
	if (!newbuf)
	{
		free(str);
		free(*buf);
		*buf = 0;
		return (0);
	}
	if (buf && *buf)
		ft_memcpy(newbuf, *buf, *buflen);
	i = 0;
	while (str[i])
	{
		newbuf[*buflen + i] = str[i];
		i++;
	}
	*buflen = *buflen + ft_strlen(str);
	if (buf && *buf)
		free(*buf);
	*buf = newbuf;
	free(str);
	return (1);
}

int	find_flag(char c, va_list *vargs, char **buf, int *buflen)
{
	char	*str;

	str = 0;
	if (c == 'c')
		return (put_char_buf(buf, buflen, va_arg(*vargs, int)));
	else if (c == 's')
		str = handle_string(va_arg(*vargs, char *));
	else if (c == 'p')
		str = handle_voidptr(va_arg(*vargs, void *));
	else if (c == 'd' || c == 'i')
		str = handle_int(va_arg(*vargs, int));
	else if (c == 'u')
		str = handle_uint(va_arg(*vargs, unsigned int));
	else if (c == 'x' || c == 'X')
		str = handle_hex(va_arg(*vargs, unsigned int), c);
	else
		return (0);
	if (str && put_str_buf(buf, buflen, str))
		return (1);
	return (0);
}

int	input_loop(const char *format, va_list *vargs, char **buf, int *buflen)
{
	int	i;
	int	ok;

	i = 0;
	ok = 1;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			if (format[i] == '%')
				ok = put_char_buf(buf, buflen, '%');
			else
				ok = find_flag(format[i], vargs, buf, buflen);
		}
		else
			ok = put_char_buf(buf, buflen, format[i]);
		if (!ok)
			return (-1);
		i++;
	}
	return (ok);
}

// va_start needs the last normal argument just so it knows where to start
int	ft_printf(const char *format, ...)
{
	va_list	va_ptr;
	char	*buf;
	int		buflen;
	int		err;

	buf = 0;
	buflen = 0;
	va_start(va_ptr, format);
	err = input_loop(format, &va_ptr, &buf, &buflen);
	va_end(va_ptr);
	if (err < 1 && buf)
		free(buf);
	if (err < 1)
		return (-1);
	if (buf)
	{
		if (ft_write_buf(buf, buflen) >= 0)
		{
			free(buf);
			return (buflen);
		}
		free(buf);
		return (-1);
	}
	return (0);
}
