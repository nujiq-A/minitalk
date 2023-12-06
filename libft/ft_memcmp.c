/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:39:48 by qang              #+#    #+#             */
/*   Updated: 2023/04/30 12:06:00 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (*((unsigned char *)(buf1 + i)) != *((unsigned char *)(buf2 + i)))
			return (*((unsigned char *)(buf1 + i)) -
					*((unsigned char *)(buf2 + i)));
		i++;
	}
	return (0);
}

/*#include <string.h>
int	main(int argc, char **argv)
{
	char	*s = argv[1];
	char	*s1 = argv[2];
	int		n = atoi(argv[3]);
	(void)argc;
	
	if (!ft_memcmp(s, s1, n))
		printf("my function: strings are equal up to %d letters\n", n);
	else 
		printf("my function: strings are different\n");
	if (!memcmp(s, s1, n))
		printf("lib function: strings are equal up to %d letters\n", n);
	else 
		printf("lib function: strings are different\n");	
}*/
