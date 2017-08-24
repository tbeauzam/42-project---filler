/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addendum_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:36:47 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 15:29:53 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						check_wildcard(t_params **params, va_list ap)
{
	if ((*params)->width[0] == '*')
	{
		ft_strdel(&(*params)->width);
		if (!((*params)->width = ft_itoa(va_arg(ap, int))))
			return (0);
	}
	if ((*params)->prec[0] == '*')
	{
		ft_strdel(&(*params)->prec);
		if (!((*params)->prec = ft_itoa(va_arg(ap, int))))
			return (0);
	}
	if (ft_atoi((*params)->prec) < 0)
		(*params)->prec[0] = '\0';
	return (1);
}

int						check_flag(char c)
{
	if (ft_strchr(CONV_LIST, c))
		return (1);
	if (ft_strchr(FLAG_LIST, c))
		return (1);
	return (0);
}

static char				**fill_chars(void)
{
	char	**t;
	int		i;

	t = NULL;
	if (!(t = (char **)malloc(sizeof(char *) * (NB_CONV + 1))))
		return (NULL);
	i = 0;
	while (i < NB_CONV + 1)
	{
		t[i] = NULL;
		i += 1;
	}
	t[0] = ft_strdup("sS");
	t[1] = ft_strdup("cC");
	t[2] = ft_strdup("diouxXDOU");
	t[3] = ft_strdup("p");
	t[4] = ft_strdup("%");
	t[5] = ft_strdup("Y");
	return (t);
}

static t_handle_conv	*fill_functions(void)
{
	t_handle_conv		*f;
	int					i;

	f = NULL;
	if (!(f = (t_handle_conv *)malloc(sizeof(t_handle_conv) * (NB_CONV + 1))))
		return (NULL);
	i = 0;
	while (i < NB_CONV + 1)
	{
		f[i] = NULL;
		i += 1;
	}
	f[0] = handle_s;
	f[1] = handle_c;
	f[2] = handle_int;
	f[3] = handle_p;
	f[4] = handle_percent;
	f[5] = handle_error;
	return (f);
}

t_conv_tab				**create_conv_tab(void)
{
	int				i;
	char			**letters;
	t_handle_conv	*functions;
	t_conv_tab		**tab;

	tab = NULL;
	letters = fill_chars();
	functions = fill_functions();
	i = 0;
	if (!(tab = (t_conv_tab **)malloc((NB_CONV + 1) * sizeof(t_conv_tab *))))
		return (NULL);
	while (letters[i])
	{
		if (!(tab[i] = (t_conv_tab *)malloc(sizeof(t_conv_tab))))
			return (NULL);
		tab[i]->c = ft_strdup(letters[i]);
		tab[i]->f = functions[i];
		ft_strdel(&letters[i]);
		i += 1;
	}
	free(letters);
	free(functions);
	tab[i] = NULL;
	return (tab);
}
