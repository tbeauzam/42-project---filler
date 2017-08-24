/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:11:19 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/11 00:27:12 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t				i;
	unsigned char		*temp_dst;
	unsigned const char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned const char *)src;
	if (temp_dst <= temp_src)
		return (ft_memcpy(dst, src, len));
	else
	{
		i = len;
		while (i != 0)
		{
			temp_dst[i - 1] = temp_src[i - 1];
			i -= 1;
		}
		return (dst);
	}
}
