/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:18:11 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/09 16:54:35 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*init(size_t *i, char const *haystack)
{
	char	*tmp_h;

	*i = 0;
	tmp_h = (char *)haystack;
	return (tmp_h);
}

char			*ft_strstr(char const *haystack, char const *needle)
{
	size_t	i;
	size_t	j;
	size_t	backup;
	char	*tmp_h;

	tmp_h = init(&i, haystack);
	if (needle[0] == 0)
		return (tmp_h);
	while (i < ft_strlen(tmp_h))
	{
		j = 0;
		backup = i;
		if (i < ft_strlen(tmp_h) && needle[j] != 0 && tmp_h[i] == needle[j])
		{
			while (i < ft_strlen(tmp_h) && tmp_h[i] == needle[j])
			{
				i += 1;
				j += 1;
			}
			if (tmp_h[i - 1] == needle[j - 1] && needle[j] == 0)
				return (tmp_h + backup);
		}
		i = backup + 1;
	}
	return (NULL);
}
