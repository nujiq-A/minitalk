/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:01:34 by qang              #+#    #+#             */
/*   Updated: 2023/05/08 14:42:18 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_strchr((char *)set, *s1) && *s1)
	{
		s1++;
		len--;
	}
	while (ft_strchr((char *)set, s1[len - 1]) && len > 0)
		len--;
	if (len <= 0)
		return (ft_strdup(""));
	return (ft_substr(s1, 0, len));
}

/*int main(void)
{
    char *s1 = "   \t      \n   \t";
    char *set = " \t\n";
    char *trimmed = ft_strtrim(s1, set);

    printf("Original string: '%s'\n", s1);
    printf("Trimmed string: '%s'\n", trimmed);

    free(trimmed); // Remember to free the memory allocated by ft_substr

    return 0;
}*/
