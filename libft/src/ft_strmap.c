/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:16:05 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 01:32:19 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		if (!(result = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		while (i < len)
		{
			result[i] = f(s[i]);
			i += 1;
		}
		result[i] = '\0';
		return (result);
	}
	else
		return (NULL);
}
