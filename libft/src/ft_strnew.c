/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:59:12 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/07 15:06:14 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (i < size)
	{
		s[i] = '\0';
		i += 1;
	}
	s[i] = '\0';
	return (s);
}
