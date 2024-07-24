/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:26:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/07/22 12:03:54 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h> // uintptr
# include <stdarg.h> // va_*()

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del) (void *));
void	ft_lstclear(t_list **lst, void (*del) (void *));
void	ft_lstiter(t_list *lst, void (*f) (void *));
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));
int		ft_atoi_safe(const char *str, int *err_atoi);
int		ft_atoi_safe2(const char *str, int *err_atoi);
// ft_printf
int		get_hexlen(uintptr_t n);
int		ft_write_buf(char *buf, int buflen);
char	*ft_itoa_long(long int n);
char	*handle_string(char *s);
char	*handle_voidptr(void *ptr);
char	*handle_int(int n);
char	*handle_uint(unsigned int n);
char	*handle_hex(uintptr_t n, char hexcase);
int		ft_printf(const char *format, ...);
// get_net_line
//void	*ft_memcpy(void *dst, const void *src, size_t n);
void	cleanup(char **storage, int *storagesize);
int		get_linelen(char **storage, int	*storagesize);
int		put_in_storage(char **storage, int *storagesize, char *buf,
			int readsize);
int		has_newline(char **storage, int *storagesize);
char	*get_next_line(int fd);
#endif
