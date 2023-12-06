/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:51:01 by qang              #+#    #+#             */
/*   Updated: 2023/05/11 10:42:11 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	if ((8 < *str && *str < 14) || *str == ' ')
	{
		while ((8 < *str && *str < 14) || *str == ' ')
			str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + *str - 48;
		str++;
	}
	if (sign == 1)
		return (-i);
	else
		return (i);
}
