/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:06:32 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 16:25:41 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst)
	{
		temp = *alst;
		while (temp)
		{
			del(temp->content, temp->content_size);
			free(temp);
			*alst = NULL;
			temp = temp->next;
		}
	}
}
