/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:59:29 by qang              #+#    #+#             */
/*   Updated: 2023/06/25 14:15:41 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, int *count, int c)
{
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (n > 15)
		ft_puthex(n / 16, count, c);
	n = n % 16;
	if (c == 'x')
		s_putchar(base1[n], count);
	else
		s_putchar(base2[n], count);
}

size_t	hdigits(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	writebase(int *count, t_flag *flags, int c)
{
	if (flags->base)
	{
		if (c == 'x')
			*count += write(1, "0x", 2);
		else
			*count += write(1, "0X", 2);
	}
}

void	s_puthex7(unsigned int n, int *count, t_flag *flags, int c)
{
	size_t	len;

	len = hdigits(n);
	if (flags->base && n != 0 && !(flags->prec > flags->width))
		len += 2;
	if (flags->prec > len)
		s_puthex3(n, count, flags, c);
	else
	{
		if (flags->justify)
			s_puthex5(n, count, flags, c);
		else
			s_puthex6(n, count, flags, c);
	}
}

void	s_puthex6(unsigned int n, int *count, t_flag *flags, int c)
{
	size_t	len;
	size_t	prec;

	prec = flags->prec;
	len = hdigits(n);
	if (flags->base && n != 0 && !(flags->prec > flags->width))
		len += 2;
	if (flags->pad && !(flags->precision))
	{
		writebase(count, flags, c);
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_puthex(n, count, c);
	}
	else
	{
		while ((flags->width)-- > len)
			s_putchar(' ', count);
		writebase(count, flags, c);
		ft_puthex(n, count, c);
	}
}
