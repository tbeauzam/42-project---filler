/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:22:02 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 15:17:16 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_p_thing(int wid_padd, int prec_padd)
{
	ft_putnchar(' ', wid_padd);
	ft_putstr("0x");
	ft_putnchar('0', prec_padd);
}

static void		print_p_thing2(int wid_padd, int prec_padd)
{
	ft_putstr("0x");
	ft_putnchar('0', prec_padd + wid_padd);
}

static int		print_addr(t_params *p, char *s, int prec_padd, int wid_padd)
{
	int		len;

	len = ft_strlen(s);
	ft_lower_str(s);
	if (ft_atoi(p->width) < 0 || ft_strchr(p->flags, '-'))
	{
		ft_putstr("0x");
		print_that_thing(s, prec_padd, wid_padd);
	}
	else
	{
		if (ft_strchr(p->flags, '0'))
		{
			if (wid_padd > prec_padd && ft_atoi(p->prec) == 0)
				print_p_thing2(wid_padd, prec_padd);
			else
				print_p_thing(wid_padd, prec_padd);
		}
		else
			print_p_thing(wid_padd, prec_padd);
		ft_putstr(s);
	}
	if (ft_strlen(s))
		ft_strdel(&s);
	return (len + prec_padd + wid_padd + 2);
}

int				handle_p(t_params *params, va_list ap, char conv)
{
	char	*arg;
	int		len;
	int		prec_padding;
	int		wid_padding;
	int		special;

	conv = 0;
	if (!(check_wildcard(&params, ap)))
		return (-1);
	if (!(arg = ft_alltoa_base(va_arg(ap, long), 16)))
		arg = ft_strdup("0");
	len = ft_strlen(arg);
	check_wp_p(params, &len, &prec_padding, &wid_padding);
	special = 0;
	if (arg[0] == '0' && params->prec[0] != '\0' && ft_atoi(params->width))
		special += 1;
	if (arg[0] == '0' && params->prec[0] != '\0'
			&& !(ft_atoi(params->prec)))
	{
		params->flags = ft_str_remc(params->flags, '#');
		ft_strdel(&arg);
		return (print_addr(params, "", prec_padding, wid_padding + special));
	}
	return (print_addr(params, arg, prec_padding, wid_padding));
}
