/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:41:51 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 15:25:37 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_flags(char *s, char *temp, int *ret)
{
	int			i;
	int			j;

	ft_bzero(temp, sizeof(temp));
	i = 0;
	j = 0;
	while (s[i] && ft_strchr(FLAGS, s[i]))
	{
		if (!ft_strchr(temp, s[i]))
		{
			temp[j] = s[i];
			j += 1;
		}
		i += 1;
	}
	*ret = i;
	return (temp);
}

static char			*get_width(char *s, char *temp)
{
	int		i;
	int		j;

	ft_bzero(temp, sizeof(temp));
	i = 0;
	j = 0;
	if (s[i] == '*')
		temp[j] = '*';
	else
	{
		while (ft_isdigit(s[i]))
		{
			temp[j] = s[i];
			j += 1;
			i += 1;
		}
	}
	return (temp);
}

static char			*get_precision(char *s, char *temp, int *i, int j)
{
	ft_bzero(temp, sizeof(temp));
	if (s[*i] == '.')
	{
		*i += 1;
		if (s[*i] == '*')
		{
			*i += 1;
			temp[j] = '*';
		}
		else
		{
			if (ft_isdigit(s[*i]))
			{
				while (ft_isdigit(s[*i]))
				{
					temp[j] = s[*i];
					*i += 1;
					j += 1;
				}
			}
			else
				temp[j] = '0';
		}
	}
	return (temp);
}

static char			*get_size(char *s, char *temp)
{
	int		i;
	int		j;

	ft_bzero(temp, sizeof(temp));
	i = 0;
	j = 0;
	if (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 'z')
	{
		temp[j] = s[i];
		i += 1;
		if ((temp[j] == 'h' || temp[j] == 'l') && s[i] == temp[j])
		{
			j += 1;
			temp[j] = s[i];
			i += 1;
		}
	}
	return (temp);
}

t_params			*get_params(char *s, char c, int ret, int i)
{
	t_params	*params;
	char		temp[101];

	if (!(params = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	if (!(params->flags = ft_strdup(get_flags(s + i, temp, &ret))))
		return (NULL);
	i += ret;
	if (!(params->width = ft_strdup(get_width(s + i, temp))))
		return (NULL);
	i += ft_strlen(params->width);
	ret = 0;
	if (!(params->prec = ft_strdup(get_precision(s + i, temp, &ret, 0))))
		return (NULL);
	i += ret;
	if (!(params->size = ft_strdup(get_size(s + i, temp))))
		return (NULL);
	i += ft_strlen(params->size);
	if (s[i] != c && s[i] != '\0')
		return (NULL);
	params->next = NULL;
	return (params);
}
