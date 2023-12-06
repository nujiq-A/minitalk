/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:14:47 by qang              #+#    #+#             */
/*   Updated: 2023/06/25 14:13:58 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	r_addy(uintptr_t addy, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (addy > 15)
		r_addy(addy / 16, count);
	addy %= 16;
	s_putchar(base[addy], count);
}

static size_t	len(uintptr_t addy)
{
	size_t	i;

	i = 0;
	if (addy == 0)
		return (1);
	while (addy > 0)
	{
		addy /= 16;
		i++;
	}
	return (i);
}

static void	s_putaddr3(uintptr_t addy, int *count, t_flag *flags, size_t i)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->prec > i)
	{
		while ((flags->width)-- > prec + 2)
			s_putchar(' ', count);
		*count += write(1, "0x", 2);
		while ((flags->prec)-- > i)
			s_putchar('0', count);
		r_addy(addy, count);
	}
	else
	{
		while ((flags->width)-- > i + 2)
			s_putchar(' ', count);
		*count += write(1, "0x", 2);
		while ((flags->prec)-- > i + 2)
			s_putchar('0', count);
		r_addy(addy, count);
	}
}

static void	s_putaddr2(uintptr_t addy, int *count, t_flag *flags, size_t i)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->justify)
	{
		*count += write(1, "0x", 2);
		while ((flags->prec)-- > i + 2)
			s_putchar('0', count);
		r_addy(addy, count);
		while ((flags->width)-- > i + 2 + prec)
			s_putchar(' ', count);
	}
	else
	{
		if (flags->pad && !(flags->precision))
		{
			*count += write(1, "0x", 2);
			while ((flags->width)-- > i + 2)
				s_putchar('0', count);
			r_addy(addy, count);
		}
		else
			s_putaddr3(addy, count, flags, i);
	}
}

void	s_putaddr(uintptr_t addy, int *count, t_flag *flags)
{
	size_t	i;
	size_t	prec;

	prec = flags->prec;
	i = len(addy);
	if (flags->prec >= flags->width)
	{
		*count += write(1, "0x", 2);
		if (flags->prec > i)
			while ((flags->prec)-- > i)
				s_putchar('0', count);
		else
			while ((flags->prec)-- > i + 2)
				s_putchar('0', count);
		r_addy(addy, count);
	}
	else
		s_putaddr2(addy, count, flags, i);
}
