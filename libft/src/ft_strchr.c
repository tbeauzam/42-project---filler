/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:17:22 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 00:46:23 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(s);
	temp = (char *)s;
	while (i < len)
	{
		if (s[i] == c)
		{
			temp += i;
			return (temp);
		}
		i += 1;
	}
	if (s[i] == '\0' && c == '\0')
	{
		temp += i;
		return (temp);
	}
	return (NULL);
}
