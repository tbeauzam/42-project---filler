/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:17:37 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 14:29:45 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] != 0 && (unsigned char)s2[i] != 0 && i < n - 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i += 1;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
