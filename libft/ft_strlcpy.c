/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:57:16 by qang              #+#    #+#             */
/*   Updated: 2023/05/06 11:43:24 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL || size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && *(src + i))
	{
		dest[i] = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*#include <string.h>

int	main(void)
{
	char	*s;
	char	d[10] = "digesting";
	s = "hello world";

//	printf("%zu\n", ft_strlcpy(d, s, 6));
//	printf("%s\n", d);

	printf("%zu\n", strlcpy(d, s, 11));
	printf("%s\n", d);
}*/
