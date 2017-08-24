/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:04:09 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/09 15:07:55 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_free(void *data, size_t content_size)
{
	char *temp;

	if (data)
	{
		temp = (char *)data;
		content_size = 0;
		ft_strdel(&temp);
	}
}
