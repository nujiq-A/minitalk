/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:45:23 by qang              #+#    #+#             */
/*   Updated: 2023/06/25 14:14:44 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	s_putstr4(char *str, int *count, t_flag *flags, size_t len)
{
	if (flags->justify)
	{
		while (*str)
			s_putchar(*str++, count);
		while ((flags->width)-- > len)
			s_putchar(' ', count);
	}
	else
	{
		while ((flags->width)-- > len)
		{
			if (flags->pad)
				s_putchar('0', count);
			else
				s_putchar(' ', count);
		}
		while (*str)
			s_putchar(*str++, count);
	}
}

static void	s_putstr3(char *str, int *count, t_flag *flags)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->justify)
	{
		while (prec--)
			s_putchar(*str++, count);
		while ((flags->width)-- > flags->prec)
			s_putchar(' ', count);
	}
	else
	{
		while ((flags->width)-- > prec)
		{
			if (flags->pad)
				s_putchar('0', count);
			else
				s_putchar(' ', count);
		}
		while (prec--)
			s_putchar(*str++, count);
	}
}

static void	s_putstr2(char *str, int *count, t_flag *flags, size_t len)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->justify)
	{
		while (*str)
			s_putchar(*str++, count);
		while ((flags->width)-- > len)
			s_putchar(' ', count);
	}
	else
	{
		while ((flags->width)-- > len)
		{
			if (flags->pad)
				s_putchar('0', count);
			else
				s_putchar(' ', count);
		}
		while (*str)
			s_putchar(*str++, count);
	}
}

void	s_putstr(char *str, int *count, t_flag *flags)
{
	size_t	len;
	size_t	prec;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	prec = flags->prec;
	if (flags->precision)
	{
		if (flags->prec >= len)
			s_putstr2(str, count, flags, len);
		else
			s_putstr3(str, count, flags);
	}
	else
		s_putstr4(str, count, flags, len);
}
