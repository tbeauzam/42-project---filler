/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:09:07 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 23:54:38 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	i = 0;
	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i += 1;
	}
	return (dst);
}
