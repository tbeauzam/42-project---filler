/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:46:18 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/10 13:55:12 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*remove_char(char *s, char c, int len)
{
	char	*result;
	char	temp[len + 1];
	int		i;
	int		j;

	ft_memset(temp, '\0', sizeof(temp));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			temp[j] = s[i];
			j += 1;
		}
		i += 1;
	}
	ft_strdel(&s);
	return (result = ft_strdup(temp));
}

char		*ft_str_remc(char *s, char c)
{
	if (!s)
		return (NULL);
	if (ft_strchr(s, c))
		return (remove_char(s, c, ft_strlen(s)));
	else
		return (s);
}
