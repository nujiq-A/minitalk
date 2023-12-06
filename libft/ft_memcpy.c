/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:55:14 by qang              #+#    #+#             */
/*   Updated: 2023/05/08 15:01:42 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*srd;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	srd = src;
	i = 0;
	temp = dest;
	while (i < n)
	{
		temp[i] = (unsigned char)srd[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main() {
    char source_str[] = "Hello, world!";
    char dest_str[20];
    ft_memcpy(dest_str, source_str, strlen(source_str) + 1);
    printf("Copied string: %s\n", dest_str);
    int source_nums[] = {1, 2, 3, 4, 5};
    int dest_nums[5];
    memcpy(dest_nums, source_nums, sizeof(source_nums));
    for (int i = 0; i < 5; i++) {
        printf("Copied integer: %d\n", dest_nums[i]);
    }

    return 0;
}*/
