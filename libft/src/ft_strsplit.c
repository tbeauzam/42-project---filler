/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:44:10 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/11/10 15:01:30 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			count += 1;
			while (s[i] != c && s[i] != 0)
				i += 1;
		}
		else
			i += 1;
	}
	return (count);
}

static size_t	ft_len_word(char const *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (i < ft_strlen(s) && s[i] != c)
	{
		i += 1;
		len += 1;
	}
	return (len);
}

static char		*ft_create_word(char const *s, size_t *i, size_t len_word)
{
	size_t	j;
	char	*word;

	if (!(word = (char *)malloc((len_word + 1) * sizeof(char))))
		return (NULL);
	word[len_word] = '\0';
	j = 0;
	while (j < len_word)
	{
		word[j] = s[*i];
		*i += 1;
		j += 1;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		nb_words;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	if (!(tab = (char **)malloc((nb_words + 1) * sizeof(char *))))
		return (NULL);
	while (i < ft_strlen(s) && nb_words > 0)
	{
		if (s[i] != '\0' && s[i] != c)
		{
			if (!(tab[j] = ft_create_word(s, &i, ft_len_word(s, i, c))))
				tab[j] = NULL;
			j += 1;
		}
		else
			i += 1;
	}
	tab[j] = NULL;
	return (tab);
}
