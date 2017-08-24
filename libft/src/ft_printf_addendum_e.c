/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addendum_e.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 00:33:40 by chkropok          #+#    #+#             */
/*   Updated: 2017/01/12 15:28:53 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	change_paddings_in_d(int *p_padd, int *w_padd)
{
	*p_padd += *w_padd;
	*w_padd -= *w_padd;
}

void	print_that_thing(char *s, int p_padd, int w_padd)
{
	ft_putnchar('0', p_padd);
	ft_putstr(s);
	ft_putnchar(' ', w_padd);
}

char	*handle_that_delicate_case(char **s)
{
	char	*new;

	new = NULL;
	new = ft_itoa((int)ft_atol(*s));
	ft_strdel(s);
	return (new);
}

int		special_d_print(t_params *p, int w_padd)
{
	if (p->width[0] != '\0')
	{
		ft_putnchar(' ', w_padd);
		return (w_padd);
	}
	return (0);
}

void	check_width_u(t_params *params, int len, int *w_padd, int prec_padding)
{
	*w_padd = 0;
	if (ft_abs(ft_atoi(params->width)) > len + prec_padding)
	{
		*w_padd = ft_abs(ft_atoi(params->width)) - (len + prec_padding);
		if (ft_atoi(params->width) < 0)
			*w_padd = ft_abs(*w_padd);
	}
}
