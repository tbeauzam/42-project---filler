/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:21:22 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/08 16:47:41 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		elem->next = NULL;
		if (!content)
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		else
		{
			if (!(elem->content = (void *)malloc(content_size)))
				return (NULL);
			elem->content = ft_memmove(elem->content, content, content_size);
			elem->content_size = content_size;
		}
	}
	return (elem);
}
