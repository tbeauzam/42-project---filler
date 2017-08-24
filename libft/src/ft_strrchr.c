/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:17:53 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 00:57:03 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;
	char	*temp;

	i = ft_strlen(s);
	temp = (char *)s;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			temp += i;
			return (temp);
		}
		i -= 1;
	}
	return (NULL);
}
