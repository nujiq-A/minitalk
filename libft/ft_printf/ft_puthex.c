/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:00:19 by qang              #+#    #+#             */
/*   Updated: 2023/06/25 14:15:18 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_puthex5(unsigned int n, int *count, t_flag *flags, int c)
{
	size_t	len;
	size_t	prec;

	prec = flags->prec;
	len = hdigits(n);
	if (flags->base && n != 0 && !(flags->prec > flags->width))
		len += 2;
	if (flags->pad)
	{
		writebase(count, flags, c);
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_puthex(n, count, c);
	}
	else
	{
		writebase(count, flags, c);
		ft_puthex(n, count, c);
		while ((flags->width)-- > len)
			s_putchar(' ', count);
	}
}

void	s_puthex4(unsigned int n, int *count, t_flag *flags, int c)
{
	size_t	len;
	size_t	prec;

	prec = flags->prec;
	len = hdigits(n);
	if (flags->base && n != 0 && !(flags->prec > flags->width))
		len += 2;
	while ((flags->width)-- > flags->prec)
		s_putchar(' ', count);
	writebase(count, flags, c);
	while ((flags->prec)-- > len)
		s_putchar('0', count);
	ft_puthex(n, count, c);
}

void	s_puthex3(unsigned int n, int *count, t_flag *flags, int c)
{
	size_t	len;
	size_t	prec;

	prec = flags->prec;
	len = hdigits(n);
	if (flags->base && n != 0 && !(flags->prec > flags->width))
		len += 2;
	if (flags->justify)
	{
		writebase(count, flags, c);
		while ((flags->prec)-- > len)
			s_putchar('0', count);
		ft_puthex(n, count, c);
		while ((flags->width)-- > prec)
			s_putchar(' ', count);
	}
	else
		s_puthex4(n, count, flags, c);
}

void	s_puthex2(unsigned int n, int *count, t_flag *flags, int c)
{
	size_t	len;
	size_t	prec;

	prec = flags->prec;
	len = hdigits(n);
	if (flags->base && n != 0 && !(flags->prec > flags->width))
		len += 2;
	if (flags->prec > len)
	{
		writebase(count, flags, c);
		while ((flags->prec)-- > len)
			s_putchar('0', count);
		ft_puthex(n, count, c);
	}
	else
	{
		writebase(count, flags, c);
		ft_puthex(n, count, c);
	}
}

void	s_puthex(unsigned int n, int *count, t_flag *flags, int c)
{
	size_t	len;
	size_t	prec;

	prec = flags->prec;
	len = hdigits(n);
	if (flags->base && n != 0 && !(flags->prec > flags->width))
		len += 2;
	if (flags->base && n == 0)
		flags->base = 0;
	if (n == 0 && flags->precision && !(flags->prec))
	{
		while ((flags->width)--)
			s_putchar(' ', count);
		return ;
	}
	if (flags->prec >= flags->width)
		s_puthex2(n, count, flags, c);
	else
		s_puthex7(n, count, flags, c);
}
