/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:24:59 by qang              #+#    #+#             */
/*   Updated: 2023/05/08 14:55:14 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_malloc(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*temp;
	int		k;

	nb = n;
	k = to_malloc(nb);
	temp = (char *)malloc(sizeof(char) * (k + 1));
	if (temp == NULL)
		return (NULL);
	if (nb == 0)
		temp[0] = 48;
	else if (nb < 0)
	{
		temp[0] = '-';
		nb = -nb;
	}
	temp[k] = '\0';
	while (nb)
	{
		temp[--k] = nb % 10 + 48;
		nb /= 10;
	}
	return (temp);
}
