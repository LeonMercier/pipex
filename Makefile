# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 11:56:58 by lemercie          #+#    #+#              #
#    Updated: 2024/08/21 15:52:12 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
#CFLAGS	:= -Wextra -Wall -Werror
CFLAGS	:= 
NAME	:= pipex
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBFT)
SRCDIR	:= ./src/
SRCS	:= $(addprefix $(SRCDIR),pipex.c)
OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft: 
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS) ./include/pipex.h
	$(CC) $(OBJS) $(LIBFT)/libft.a $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libft
