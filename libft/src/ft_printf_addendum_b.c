/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addendum_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 13:59:08 by chkropok          #+#    #+#             */
/*   Updated: 2017/01/12 15:33:26 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				inc_char_len(wint_t c)
{
	int		len;
	char	*bin_len;

	len = 0;
	bin_len = ft_itoa_base(c, 2);
	if (ft_strlen(bin_len) < 8)
		len = 1;
	else if (ft_strlen(bin_len) < 12)
		len = 2;
	else if (ft_strlen(bin_len) < 17)
		len = 3;
	else if (ft_strlen(bin_len) < 22)
		len = 4;
	ft_strdel(&bin_len);
	return (len);
}

int				wchar_len(wchar_t *s, int *len, char *prec)
{
	int		i;
	int		count;
	int		char_len;

	i = 0;
	count = 0;
	while (s[i])
	{
		char_len = 0;
		char_len = inc_char_len(s[i]);
		if (prec[0] && ft_atoi(prec) < count + char_len)
			break ;
		count += char_len;
		*len += 1;
		i += 1;
	}
	return (count);
}

static int		check_conv(char *s, char *temp)
{
	int		i;

	i = 1;
	while (s[i] || (s[1] == '\0' && s[0] == '%'))
	{
		if (ft_strchr(CONV_LIST, s[i]) || !(check_flag(s[i]))
				|| (!(ft_strchr(CONV_LIST, s[i])) && check_flag(s[i])
					&& s[i + 1] == '\0') || (s[0] == '%' && s[1] == '\0'))
		{
			i += 1;
			ft_memmove(temp, s, i);
			temp[i] = '\0';
			return (i);
		}
		i += 1;
	}
	return (0);
}

int				get_conversions(t_list2 **list, char *s, int i)
{
	t_list2		*elem;
	char		tmp[ft_strlen(s) + 2];
	int			len;

	elem = *list;
	while (s[i])
	{
		ft_memset(tmp, '\0', sizeof(tmp));
		if (s[i] == '%')
		{
			len = check_conv(s + i, tmp);
			if (!elem)
			{
				elem = create_lstd(tmp, ft_strlen(tmp) + 1);
				*list = elem;
			}
			else
				lstdadd_back(&elem, create_lstd(tmp, ft_strlen(tmp) + 1));
			savage_incrementation(&i, len);
		}
		else
			i += 1;
	}
	return (0);
}

t_params		*create_params_list(t_params **head, t_list2 *conv_list)
{
	char		conv;
	char		*s;
	t_list2		*tmp;
	t_params	*cursor;

	tmp = conv_list;
	cursor = NULL;
	s = tmp->content;
	conv = s[ft_strlen(s) - 1];
	if (!tmp || !(cursor = get_params(s, conv, 0, 1)))
		return (NULL);
	*head = cursor;
	while (tmp->next)
	{
		tmp = tmp->next;
		s = tmp->content;
		conv = s[ft_strlen(s) - 1];
		if (!(cursor->next = get_params(s, conv, 0, 1)))
			return (NULL);
		cursor = cursor->next;
	}
	return (*head);
}
