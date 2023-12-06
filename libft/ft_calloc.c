/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:02:22 by qang              #+#    #+#             */
/*   Updated: 2023/05/11 15:39:22 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void			*temp;
	size_t			n;

	n = nitems * size;
	if (n < nitems || n < size)
		return (NULL);
	temp = (void *)malloc(n);
	if (!temp)
		return (NULL);
	while (n--)
		*((unsigned char *)temp + n) = 0;
	return (temp);
}
