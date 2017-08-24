/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:20:13 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 14:23:10 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		len;
	size_t		dst_len;

	i = 0;
	len = size - ft_strlen(dst) - 1;
	dst_len = ft_strlen(dst);
	while (i < len && dst_len < size)
	{
		dst[dst_len + i] = src[i];
		i += 1;
	}
	dst[dst_len + i] = '\0';
	if (size < dst_len)
		return (size + ft_strlen(src));
	return (dst_len + ft_strlen(src));
}
