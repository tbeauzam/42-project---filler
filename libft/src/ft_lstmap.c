/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:07:09 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 17:50:39 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*temp;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	result = NULL;
	result = f(ft_lstnew(lst->content, lst->content_size));
	temp = result;
	lst = lst->next;
	while (lst)
	{
		elem = f(ft_lstnew(lst->content, lst->content_size));
		temp->next = elem;
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
