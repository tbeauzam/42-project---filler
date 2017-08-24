/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:31:00 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/07 11:57:22 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;

	i = ft_strlen(s1);
	j = 0;
	len = i + ft_strlen(s2);
	while (i < len)
	{
		s1[i] = s2[j];
		i += 1;
		j += 1;
	}
	s1[i] = '\0';
	return (s1);
}
