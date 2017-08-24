/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:31:03 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/09 23:39:36 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy
	(void *dst, void const *src, int c, size_t n)
{
	size_t	i;
	char	*temp_dst;
	char	*temp_src;

	i = 0;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == c)
		{
			temp_dst += (i + 1);
			return ((void *)temp_dst);
		}
		i += 1;
	}
	return (NULL);
}
