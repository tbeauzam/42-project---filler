/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:33:01 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 14:34:54 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		len;
	char				*result;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		if (!(result = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		while (i < len)
		{
			result[i] = f(i, s[i]);
			i += 1;
		}
		result[i] = '\0';
		return (result);
	}
	else
		return (NULL);
}
