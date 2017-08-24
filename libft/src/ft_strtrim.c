/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 00:08:38 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/16 12:53:53 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(char const *s, int len, int *start, int *end)
{
	int		i;
	int		j;

	i = 0;
	j = len - 1;
	while (i < len && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i += 1;
	while (j > i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j -= 1;
	*start = i;
	*end = j + 1;
	return (*end - *start);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	int		real_len;
	char	*result;

	if (!s)
		return (NULL);
	real_len = ft_count(s, ft_strlen(s), &start, &end);
	if (!(result = (char *)malloc((real_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while ((i + start) < end)
	{
		result[i] = s[i + start];
		i += 1;
	}
	result[i] = '\0';
	return (result);
}
