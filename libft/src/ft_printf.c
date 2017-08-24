/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:56:34 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 15:27:48 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		treat_conv
	(t_list2 *conv, t_params *params, va_list ap, t_conv_tab **tab)
{
	char		*s;
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	s = conv->content;
	while (tab[i])
	{
		j = 0;
		if (tab[i]->c[j] == 'Y' || ft_strlen(s) == 1)
			return (len = tab[5]->f(params, ap, s[ft_strlen(s) - 1]));
		while (tab[i]->c[j])
		{
			if (s[ft_strlen(s) - 1] == tab[i]->c[j])
				return (len = tab[i]->f(params, ap, s[ft_strlen(s) - 1]));
			j += 1;
		}
		i += 1;
	}
	return (len);
}

static void		init_or_print_next_char(char *s, int *i, int *count, int tinker)
{
	if (tinker)
	{
		ft_putchar(s[*i]);
		*i += 1;
		*count += 1;
	}
	else
	{
		*i = 0;
		*count = 0;
	}
}

static int		handler
	(char *s, va_list ap, t_conv_tab **tab, t_list2 *conv_chain)
{
	int				i;
	int				j;
	int				count;
	t_params		*params_chain;

	params_chain = NULL;
	if (conv_chain && !(create_params_list(&params_chain, conv_chain)))
		return (-1);
	init_or_print_next_char(s, &i, &count, 0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if ((j = treat_conv(conv_chain, params_chain, ap, tab)) == -1)
				return (-1);
			count += j;
			i += conv_chain->content_size - 1;
			clean_things_up(&conv_chain, &params_chain);
		}
		else
			init_or_print_next_char(s, &i, &count, 1);
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	t_conv_tab		**tab;
	va_list			ap;
	t_list2			*conv_chain;
	char			*s;
	int				count;

	s = ft_strdup(format);
	conv_chain = NULL;
	get_conversions(&conv_chain, s, 0);
	tab = create_conv_tab();
	va_start(ap, format);
	count = handler(s, ap, tab, conv_chain);
	va_end(ap);
	ft_strdel(&s);
	dismantle_tab(tab);
	return (count);
}
