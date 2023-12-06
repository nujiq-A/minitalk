# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 12:06:42 by qang              #+#    #+#              #
#    Updated: 2023/06/25 14:34:52 by qang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
src = server client
PRINTFDIR = ./libft/ft_printf
LIBFTDIR = ./libft

all: $(src)

server: server.c $(LIBFTDIR)/libft.a
	$(CC) $(CFLAGS) $< -I $(PRINTFDIR) -I $(LIBFTDIR) -L$(LIBFTDIR) -lft -o $@

client: client.c $(LIBFTDIR)/libft.a
	$(CC) $(CFLAGS) $< -I $(PRINTFDIR) -I $(LIBFTDIR) -L$(LIBFTDIR) -lft -o $@

$(LIBFTDIR)/libft.a: $(PRINTFDIR)/libftprintf.a
	@make -C $(LIBFTDIR)

$(PRINTFDIR)/libftprintf.a:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFDIR)/libftprintf.a $(LIBFTDIR)/libft.a

clean:
	@make clean -C $(LIBFTDIR)
	@make clean -C $(PRINTFDIR)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@make fclean -C $(PRINTFDIR)
	@rm -rf $(src)

re: fclean all

.PHONY: server client all fclean clean re
