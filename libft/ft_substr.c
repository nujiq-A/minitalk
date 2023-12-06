/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:49:59 by qang              #+#    #+#             */
/*   Updated: 2023/05/10 19:31:09 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	while (s[start] && i < len)
		temp[i++] = s[start++];
	temp[i] = '\0';
	return (temp);
}

/*int main(void)
{
	char str[] = "The quick brown fox jumps over the lazy dog";
	char *sub;
	sub = ft_substr(str, 0, 42000);

	printf("Original string: %s\n", str);
	printf("Substring: %s\n", sub);

	free(sub); // don't forget to free the memory allocated by ft_substr

	return 0;
}*/
