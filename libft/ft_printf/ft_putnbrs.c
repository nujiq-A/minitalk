/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:14:14 by qang              #+#    #+#             */
/*   Updated: 2023/06/25 14:15:56 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_putnbr5(int n, int *count, t_flag *flags, size_t len)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->sign || (flags->precision && n < 0))
		prec++;
	while ((flags->width)-- > prec)
		s_putchar(' ', count);
	ft_putsign(n, count, flags);
	while ((flags->prec)-- > len)
		s_putchar('0', count);
	ft_putnbr(n, count);
}

void	s_putnbr4(int n, int *count, t_flag *flags, size_t len)
{
	if (flags->pad)
	{
		ft_putsign(n, count, flags);
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_putnbr(n, count);
	}
	else
	{
		ft_putsign(n, count, flags);
		ft_putnbr(n, count);
		while ((flags->width)-- > len)
			s_putchar(' ', count);
	}
}

void	s_putnbr3(int n, int *count, t_flag *flags, size_t len)
{
	size_t	prec;

	prec = flags->prec;
	ft_putsign(n, count, flags);
	while (prec-- > len)
		s_putchar('0', count);
	ft_putnbr(n, count);
	if (n < 0)
		(flags->width)--;
	while ((flags->width)-- > flags->prec)
		s_putchar(' ', count);
}

void	s_putnbr2(int n, int *count, t_flag *flags, size_t len)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->prec > len)
	{
		ft_putsign(n, count, flags);
		while ((flags->prec)-- > len)
			s_putchar('0', count);
		ft_putnbr(n, count);
	}
	else
	{
		ft_putsign(n, count, flags);
		ft_putnbr(n, count);
	}
}

void	s_putnbr(int n, int *count, t_flag *flags)
{
	size_t	len;
	size_t	prec;

	prec = flags->prec;
	len = digits(n);
	if (flags->space || flags->sign || n < 0)
		len++;
	if (flags->precision && n < 0)
		len--;
	if (flags->pad && flags->justify)
		flags->pad = 0;
	if (flags->precision && !(flags->prec) && n == 0)
	{
		while ((flags->width)--)
			s_putchar(' ', count);
		return ;
	}
	if (flags->prec >= flags->width)
		s_putnbr2(n, count, flags, len);
	else
		s_putnbr7(n, count, flags, len);
}
