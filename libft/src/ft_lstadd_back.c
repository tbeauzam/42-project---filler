/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:59:02 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/08 14:02:18 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new_elem)
{
	t_list	*temp;

	temp = *alst;
	if (!temp)
		temp = new_elem;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_elem;
	}
}
