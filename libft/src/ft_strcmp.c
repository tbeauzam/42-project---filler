/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:17:04 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 11:02:49 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while ((unsigned char)s1[i] != 0 && (unsigned char)s2[i] != 0)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i += 1;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
