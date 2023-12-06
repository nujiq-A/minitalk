/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:02:31 by qang              #+#    #+#             */
/*   Updated: 2023/07/12 14:14:46 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	signal_sent(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("\xE2\x9C\x85 Message sent\n");
}

void	send_signal(pid_t pid, char *str)
{
	int	bit;

	if (!*str)
	{
		bit = 8;
		while (bit--)
		{
			kill(pid, SIGUSR2);
			usleep(500);
		}
	}
	while (*str)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (*str & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(500);
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac == 3)
	{
		if (!*(av[2]))
		{
			ft_printf("Empty message\n");
			return (1);
		}
		server_pid = ft_atoi(av[1]);
		send_signal(server_pid, av[2]);
		signal(SIGUSR2, signal_sent);
		send_signal(server_pid, "\0");
	}
	else
	{
		ft_printf("    ━━╮\n╰┃ ┣▇━▇\n ┃ ┃  ╰━▅╮\n ╰┳╯ ╰━━┳╯GET ON MY LVL😎\n");
		ft_printf("  ╰╮ ┳━━╯ SUPER EASY🤙\n ▕▔▋ ╰╮╭━╮NICE TUTORIAL😂\n");
		ft_printf("╱▔╲▋╰━┻┻╮╲╱▔▔╲\n▏  ▔▔▔▔  O O┃\n╲╱▔╲▂▂▂▂╱▔╲▂▂╱\n");
		ft_printf(" ▏╳▕▇▕ ▏╳▕▇▇▕\n ╲▂╱╲▂╱ ╲▂╱");
		return (1);
	}
}
