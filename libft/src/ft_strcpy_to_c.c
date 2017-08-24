/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_to_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:40:38 by chkropok          #+#    #+#             */
/*   Updated: 2016/11/30 12:12:45 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcpy_to_c(char *dest, char *src, size_t len, char c)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (i);
	while (src[i] != c && i < len)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (i);
}
