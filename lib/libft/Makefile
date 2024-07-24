# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:50:44 by lemercie          #+#    #+#              #
#    Updated: 2024/07/22 12:04:15 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ft_printf/
GNL = get_next_line/

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atoi_safe.c \
	   ft_atoi_safe_2.c

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			 ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCS_FT_PRINTF = $(FT_PRINTF)ft_itoa_long.c $(FT_PRINTF)ft_printf.c \
				 $(FT_PRINTF)ft_printf_conversions.c \
				 $(FT_PRINTF)ft_printf_hexhandler.c \
				 $(FT_PRINTF)ft_printf_utils.c 

SRCS_GNL = $(GNL)get_next_line.c $(GNL)get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_FT_PRINTF = $(SRCS_FT_PRINTF:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_BONUS) $(OBJS_FT_PRINTF) $(OBJS_GNL)
	ar -crs $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
