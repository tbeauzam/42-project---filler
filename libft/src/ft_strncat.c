/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:54:21 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/07 12:00:48 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = ft_strlen(s1);
	j = 0;
	len = i + ft_strlen(s2);
	while (i < len && j < n)
	{
		s1[i] = s2[j];
		i += 1;
		j += 1;
	}
	s1[i] = '\0';
	return (s1);
}
