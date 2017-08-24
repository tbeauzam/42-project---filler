/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:18:25 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/09 16:14:49 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*init(size_t *i, char const *big)
{
	char	*s;

	*i = 0;
	s = (char *)big;
	return (s);
}

char			*ft_strnstr(char const *big, char const *little, size_t l)
{
	size_t	i;
	size_t	j;
	size_t	backup;
	char	*s;

	s = init(&i, big);
	if (little[0] == 0)
		return (s);
	while (i < (size_t)ft_strlen(s) && i < l)
	{
		j = 0;
		backup = i;
		if (i < (size_t)ft_strlen(s) && little[j] != 0 && s[i] == little[j])
		{
			while (i < (size_t)ft_strlen(s) && s[i] == little[j] && i < l)
			{
				i += 1;
				j += 1;
			}
			if (s[i - 1] == little[j - 1] && little[j] == 0)
				return (s + backup);
		}
		i = backup + 1;
	}
	return (NULL);
}
