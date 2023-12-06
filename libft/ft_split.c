/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:02:00 by qang              #+#    #+#             */
/*   Updated: 2023/06/24 10:37:34 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_word(char const *s, char c)
{
	int			count;
	char const	*check;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		check = s;
		while (*s != c && *s)
			s++;
		if (check < s)
			count++;
	}
	return (++count);
}

static int	n_letter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

static char	*insert(char const *s, char c, int n)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (n + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (*s && n && *s != c)
	{
		temp[i++] = *(s++);
		n--;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char		**temp;
	int			i;
	int			letter;

	i = 0;
	if (!s)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (n_word(s, c)));
	if (temp == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		letter = n_letter(s, c);
		if (letter > 0)
		{
			temp[i] = insert(s, c, letter);
			s += letter;
			i++;
		}
	}
	temp[i] = NULL;
	return (temp);
}

/*int main()
{
    char const *input = "Tripouille ";
    char **result = ft_split(input, ' ');
 	int i = 0;
    if (result[0] == NULL) {
        printf("ft_split returned NULL.\n");
        return 1;
    }

    while (result[i] != NULL) {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }

 	free(result);

    return 0;
}*/
