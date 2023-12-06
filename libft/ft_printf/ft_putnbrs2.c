/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:30:25 by qang              #+#    #+#             */
/*   Updated: 2023/06/25 14:16:14 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	digits(int n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int n, int *count)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10, count);
	nb = nb % 10 + 48;
	s_putchar(nb, count);
}

void	ft_putsign(int n, int *count, t_flag *flags)
{
	if (flags->sign)
	{
		if (n >= 0)
			s_putchar('+', count);
		else
			s_putchar('-', count);
	}
	else if (flags->space)
	{
		if (n >= 0)
			s_putchar(' ', count);
		else
			s_putchar('-', count);
	}
	else if (n < 0)
		s_putchar('-', count);
}

void	s_putnbr7(int n, int *count, t_flag *flags, size_t len)
{
	size_t	prec;

	prec = flags->prec;
	if (flags->justify)
	{
		if (flags->prec >= len)
			s_putnbr3(n, count, flags, len);
		else
			s_putnbr4(n, count, flags, len);
	}
	else
	{
		if (flags->prec > len)
			s_putnbr5(n, count, flags, len);
		else
			s_putnbr6(n, count, flags, len);
	}
}

void	s_putnbr6(int n, int *count, t_flag *flags, size_t len)
{
	if (flags->pad && !(flags->precision))
	{
		ft_putsign(n, count, flags);
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_putnbr(n, count);
	}
	else
	{
		if (flags->precision && n < 0 && (flags->width > flags->prec))
			len++;
		while ((flags->width)-- > len)
			s_putchar(' ', count);
		ft_putsign(n, count, flags);
		ft_putnbr(n, count);
	}
}
