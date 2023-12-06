# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 09:14:26 by qang              #+#    #+#              #
#    Updated: 2023/05/25 11:53:02 by qang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

srcs = ft_printf.c \
	   ft_putnbrs.c \
	   ft_putnbrs2.c \
	   ft_putchars.c \
	   ft_putui.c \
	   ft_putui2.c \
	   ft_printaddr.c \
	   ft_puthex.c \
	   ft_puthex2.c \
	   ft_putchars2.c

objs = $(srcs:.c=.o)

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
archive = ar -rc

.PHONY: bonus all clean fclean re

all: $(NAME)

$(NAME): $(objs) ft_printf.h
	$(archive) $(NAME) $(objs)

clean: 
	rm -rf $(objs)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(NAME)
