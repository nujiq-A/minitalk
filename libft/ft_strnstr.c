/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:06:12 by qang              #+#    #+#             */
/*   Updated: 2023/05/11 10:46:06 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[i] == '\0')
		return ((char *)src);
	if (!find && !src)
		return (NULL);
	while (i < n && src[i])
	{
		j = 0;
		while (src[i + j] == find[j] && (i + j) < n && src[i + j] && find[j])
			j++;
		if (find[j] == '\0')
			return ((char *)(src + i));
		i++;
	}
	return (NULL);
}

/*#include <string.h>
int	main(int ac, char **av)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	(void)ac;
	largestring = NULL; 
	ptr = strnstr(largestring, smallstring, atoi(av[1]));
	printf("%s\n", ptr);
}*/
