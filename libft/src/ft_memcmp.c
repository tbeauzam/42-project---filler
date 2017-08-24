/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:26:50 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 00:11:11 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t	i;
	char	*temp1;
	char	*temp2;

	temp1 = (char *)s1;
	temp2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)temp1[i] != (unsigned char)temp2[i])
			return ((unsigned char)temp1[i] - (unsigned char)temp2[i]);
		i += 1;
	}
	return (0);
}
