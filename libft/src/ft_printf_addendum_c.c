/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addendum_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:13:58 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 15:26:22 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_prec_o(t_params *params, char *arg, int len, int *prec_padding)
{
	*prec_padding = ft_atoi(params->prec) - len;
	if (params->prec[0] != '\0' && ft_strchr(params->flags, '#')
			&& arg[0] != '0')
		*prec_padding -= 1;
}

void	check_width_o(t_params *params, int len, int *w_padd, int prec_padding)
{
	*w_padd = 0;
	if (ft_abs(ft_atoi(params->width)) > len + prec_padding)
	{
		*w_padd = ft_abs(ft_atoi(params->width)) - (len + prec_padding);
		if (ft_atoi(params->width) < 0)
			*w_padd = ft_abs(*w_padd);
	}
}

void	check_width_x(t_params *params, int len, int *p_padd, int *w_padd)
{
	*w_padd = 0;
	if (ft_abs(ft_atoi(params->width)) > len + *p_padd)
	{
		*w_padd = ft_abs(ft_atoi(params->width)) - (len + *p_padd);
		if (ft_atoi(params->width) < 0)
			*w_padd = ft_abs(*w_padd);
	}
}

void	check_width_d(t_params *p, char *s, int *p_padd, int *w_padd)
{
	int		len;

	len = ft_strlen(s);
	*w_padd = 0;
	if (ft_abs(ft_atoi(p->width)) > len + *p_padd)
	{
		*w_padd = ft_abs(ft_atoi(p->width)) - (len + *p_padd);
		if (ft_atoi(p->width) < 0)
			*w_padd = ft_abs(*w_padd);
		if ((ft_strchr(p->flags, ' ') || ft_strchr(p->flags, '+'))
				&& s[0] != '-')
			*w_padd -= 1;
	}
}
