/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:24:01 by qang              #+#    #+#             */
/*   Updated: 2023/05/06 11:47:40 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	const unsigned char	*temp;

	if (count == 0)
		return (NULL);
	temp = buf;
	while (count--)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
	}
	return (NULL);
}

/*#include <string.h>

int main(void)
{
	char str[] = "wgat";
	char *result;

	result = (char*)memchr(str, 'z', 2453);
	if (result != NULL)
		printf("The letter 'w' was found at position %ld.\n", result - str);
	else
		printf("The letter 'w' was not found in the string.\n");
	return (0);
}*/
