/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:12 by qang              #+#    #+#             */
/*   Updated: 2023/05/03 15:18:04 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	function(unsigned int k, char *s)
{
	if (k % 3 == 0 && k % 5 == 0)
		*s = 51;
	else if (k % 3 == 0)
		*s = 53;
	else if (k % 5 == 0)
		*s = 51;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*int	main(void)
{
	char	s[] = "Zao shang hao zong guo";
	printf("before: %s\n", s);
	ft_striteri(s, function);
	printf("after : %s\n", s);
}*/
