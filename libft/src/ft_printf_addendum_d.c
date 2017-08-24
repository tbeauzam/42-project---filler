/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addendum_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:05:51 by chkropok          #+#    #+#             */
/*   Updated: 2017/01/12 13:41:46 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		destroy_elem(t_list2 **elem)
{
	char		*bloc;

	bloc = (*elem)->content;
	ft_strdel(&bloc);
	free(*elem);
	*elem = NULL;
}

static void		destroy_param(t_params **param)
{
	char		*temp;

	temp = (*param)->flags;
	ft_strdel(&temp);
	temp = (*param)->width;
	ft_strdel(&temp);
	temp = (*param)->prec;
	ft_strdel(&temp);
	temp = (*param)->size;
	ft_strdel(&temp);
	free(*param);
	*param = NULL;
}

void			clean_things_up(t_list2 **convs, t_params **params)
{
	t_list2		*temp_conv;
	t_params	*temp_param;

	temp_conv = *convs;
	if (temp_conv->next)
		*convs = temp_conv->next;
	destroy_elem(&temp_conv);
	temp_param = *params;
	if (temp_param->next)
		*params = temp_param->next;
	destroy_param(&temp_param);
}

void			dismantle_tab(t_conv_tab **tab)
{
	int			i;
	char		*temp;

	i = 0;
	while (i < NB_CONV + 1)
	{
		if (tab[i])
		{
			temp = tab[i]->c;
			ft_strdel(&temp);
			tab[i]->f = NULL;
			free(tab[i]);
			tab[i] = NULL;
		}
		i += 1;
	}
	free(tab);
}
