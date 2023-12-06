/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:07:05 by qang              #+#    #+#             */
/*   Updated: 2023/05/08 15:23:06 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

/*int main(void)
{
  char	buffer[40] = "computer program";
  char	*ptr;
  int	ch = 'p';
  ptr = ft_strrchr(buffer, ch);
  printf("The last occurrence of %c in '%s' is '%s'\n", ch, buffer, ptr);
}*/
