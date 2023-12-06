# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qang <qang@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 12:33:44 by qang              #+#    #+#              #
#    Updated: 2023/05/09 09:35:38 by qang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
rm = rm -rf
cflags = -Wall -Wextra -Werror
archive = ar -rc
cfiles = ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_memmove.c

cbfiles = ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c

cofiles = $(cfiles:.c=.o)
cbofiles = $(cbfiles:.c=.o)
ofiles = $(cofiles) \
		 $(cbofiles)

%.o: %.c
	cc $(cflags) -c $^ -o $(^:.c=.o)

$(NAME): $(ofiles) libft.h
	$(archive) $(NAME) $(cofiles)

all: $(NAME)

clean:
	$(rm) $(ofiles)

fclean: clean
	$(rm) $(NAME)

re: fclean all

bonus: $(NAME) $(cbofiles)
	$(archive) $(NAME) $(cbofiles)
