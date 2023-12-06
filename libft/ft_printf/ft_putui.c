/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:43:03 by qang              #+#    #+#             */
/*   Updated: 2023/06/25 14:16:33 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	s_putui2(unsigned int n, int *count, t_flag *flags, size_t len);
static void	s_putui3(unsigned int n, int *count, t_flag *flags, size_t len);

static size_t	digit(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	s_putui4(unsigned int n, int *count, t_flag *flags, size_t len)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->prec >= flags->width)
	{
		if (flags->prec > len)
		{
			while ((flags->prec)-- > len)
				s_putchar('0', count);
			ft_putui(n, count);
		}
		else
			ft_putui(n, count);
	}
	else
	{
		if (flags->prec > len)
			s_putui2(n, count, flags, len);
		else
			s_putui3(n, count, flags, len);
	}
}

static void	s_putui3(unsigned int n, int *count, t_flag *flags, size_t len)
{
	if (flags->pad && !(flags->precision))
	{
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_putui(n, count);
	}
	else
	{
		if (flags->justify)
		{
			ft_putui(n, count);
			while ((flags->width)-- > len)
				s_putchar(' ', count);
		}
		else
		{
			while ((flags->width)-- > len)
				s_putchar(' ', count);
			ft_putui(n, count);
		}
	}
}

static void	s_putui2(unsigned int n, int *count, t_flag *flags, size_t len)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->justify)
	{
		while ((flags->prec)-- > len)
			s_putchar('0', count);
		ft_putui(n, count);
		while ((flags->width)-- > prec)
			s_putchar(' ', count);
	}
	else
	{
		while ((flags->width)-- > flags->prec)
			s_putchar(' ', count);
		while ((flags->prec)-- > len)
			s_putchar('0', count);
		ft_putui(n, count);
	}
}

void	s_putui(unsigned int n, int *count, t_flag *flags)
{
	size_t	len;

	len = digit(n);
	if (flags->pad && flags->justify)
		flags->pad = 0;
	if (flags->precision && !(flags->prec) && n == 0)
	{
		while ((flags->width)--)
			s_putchar(' ', count);
		return ;
	}
	s_putui4(n, count, flags, len);
}
