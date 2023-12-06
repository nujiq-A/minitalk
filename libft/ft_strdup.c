/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:38:49 by qang              #+#    #+#             */
/*   Updated: 2023/05/10 18:47:22 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (temp == NULL)
		return (NULL);
	while (*(str + i))
	{
		temp[i] = *(str + i);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/*int	main(void)
{
	char c[] = "hellow rold";
	char *s = ft_strdup(c);
	printf("%s\n", s);
	free(s);
	return(0);
}*/
