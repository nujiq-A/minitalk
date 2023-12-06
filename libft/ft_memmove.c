/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:22:38 by qang              #+#    #+#             */
/*   Updated: 2023/05/08 15:02:31 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (dest == NULL && src == NULL)
		return (dest);
	dest1 = dest;
	src1 = src;
	if (src < dest)
	{	
		while (count)
		{
			dest1[count - 1] = src1[count - 1];
			count--;
		}
		return (dest);
	}
	else
	{
		while (count--)
			*(dest1++) = *(src1++);
	}
	return (dest);
}

/*#include<string.h>
int main(void)
{
	char *p;
	char s[] = "rem ipssum dolor sit a";
	char src[] = "lorem ipsum dolor sit amet";
	char *result;
	p = src+1;
	printf("src = %s\ndst = %s\n", p, src);
	result = ft_memmove(src, p, 8);
	printf("src = %s\ndst = %s\n", p, src);


    return 0;
}*/
