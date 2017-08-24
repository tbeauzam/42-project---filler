/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:16:49 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 01:39:30 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s || !(result = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		result[i] = s[start + i];
		i += 1;
	}
	result[i] = '\0';
	return (result);
}
