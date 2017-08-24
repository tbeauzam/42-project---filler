/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:26:49 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 10:50:56 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(result = (char *)malloc((ft_strlen(s1)
			+ ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i += 1;
	}
	while (j < ft_strlen(s2))
	{
		result[i] = s2[j];
		i += 1;
		j += 1;
	}
	result[i] = '\0';
	return (result);
}
