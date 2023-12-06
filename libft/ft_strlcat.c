/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:22:18 by qang              #+#    #+#             */
/*   Updated: 2023/05/08 14:24:16 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_l;
	size_t	j;
	size_t	dst_l;

	j = 0;
	i = 0;
	src_l = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (src_l);
	while (dest[i])
		i++;
	dst_l = i;
	if (size == 0 || size <= i)
		return (src_l + size);
	while (j < size - dst_l - 1 && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dst_l + src_l);
}*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_l;
	size_t	dst_l;
	size_t	i;

	i = 0;
	src_l = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (src_l);
	dst_l = ft_strlen(dest);
	if (size <= dst_l || size == 0)
		return (src_l + size);
	dest += dst_l;
	while (i < size - dst_l - 1 && *(src + i))
	{
		dest[i] = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (dst_l + src_l);
}

/*#include <string.h>

int	main(void)
{
    char c[] = "lorem ipsum dolor sit amet";
    char s[15] = "rrrrrrrrrrrrrrr";
	char *dest;
	dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 'r', 15);
    printf("%zu\n", ft_strlcat(dest, c, 5));
    printf("%s\n", c);
    //printf("%lu\n", strlcat(dest, c, 5));
    //printf("%s\n", c);
}*/
