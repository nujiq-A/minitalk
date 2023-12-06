/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:23:51 by qang              #+#    #+#             */
/*   Updated: 2023/05/03 15:15:36 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	function(unsigned int k, char l)
{
	if ('A' <= l && l <= 'Z')
		l = l + k;
	else if ('a' <= l && l <= 'z')
		l = l - k;
	return(l);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*temp;

	if (s == NULL)
		return (NULL);
	temp = ft_strdup((char *)s);
	if (temp == NULL)
		return (NULL);
	if (f == NULL)
		return (temp);
	i = 0;
	while (temp[i])
	{
		temp[i] = f(i, temp[i]);
		i++;
	}
	return (temp);
}

/*int	main(void)
{
	char	*temp;
	char	*result;
	temp = "Bing Chilling";

	result = ft_strmapi(temp, function);
	printf("%s\n", result);
}*/
