/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:13:14 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/09 13:33:23 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	int		i;
	int		len;
	char	*dup;

	len = (ft_strlen(s1));
	dup = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i += 1;
	}
	dup[i] = '\0';
	return (dup);
}
