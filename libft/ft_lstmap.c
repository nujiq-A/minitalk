/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:49:22 by qang              #+#    #+#             */
/*   Updated: 2023/05/12 13:23:13 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*curr;
	t_list	*r_temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	curr = NULL;
	r_temp = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&r_temp, del);
			return (NULL);
		}
		if (curr != NULL)
			curr->next = temp;
		else
			r_temp = temp;
		curr = temp;
		lst = lst->next;
	}
	return (r_temp);
}
