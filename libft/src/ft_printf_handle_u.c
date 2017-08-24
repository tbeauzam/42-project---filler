/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:50:39 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 12:27:54 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_u_arg(t_params *p, va_list ap, char conv, char *arg)
{
	if (conv == 'U' || (conv == 'u' && ft_strequ(p->size, "l")))
		return (arg = ft_ualltoa(va_arg(ap, unsigned long)));
	else if (ft_strequ(p->size, "hh"))
		return (arg = ft_ualltoa((unsigned char)va_arg(ap, unsigned int)));
	else if (ft_strequ(p->size, "h"))
		return (arg = ft_ualltoa((unsigned short)va_arg(ap, unsigned int)));
	else if (ft_strequ(p->size, "ll"))
		return (arg = ft_ualltoa(va_arg(ap, unsigned long long)));
	else if (ft_strequ(p->size, "j"))
		return (arg = ft_ualltoa(va_arg(ap, uintmax_t)));
	else if (ft_strequ(p->size, "z"))
		return (arg = ft_ualltoa(va_arg(ap, size_t)));
	return (arg = ft_ualltoa(va_arg(ap, unsigned int)));
}

static void		check_ht(t_params *p, int *w_padd)
{
	if (*w_padd < 0)
		*w_padd = -(*w_padd);
	if (ft_atoi(p->width) >= 0 && !(ft_strchr(p->flags, '-')))
	{
		if (ft_strchr(p->flags, '0') && p->prec[0] == '\0')
			ft_putnchar('0', *w_padd);
		else
			ft_putnchar(' ', *w_padd);
	}
}

static int		print_udecimal(t_params *p, char *s, int p_padd, int w_padd)
{
	int		len;

	len = ft_strlen(s);
	if (ft_atoi(p->width) < 0 || ft_strchr(p->flags, '-'))
	{
		check_ht(p, &w_padd);
		ft_putnchar('0', p_padd);
		ft_putstr(s);
		ft_putnchar(' ', w_padd);
	}
	else
	{
		check_ht(p, &w_padd);
		ft_putnchar('0', p_padd);
		ft_putstr(s);
	}
	if (ft_strlen(s))
		ft_strdel(&s);
	return (len + p_padd + w_padd);
}

int				handle_u(t_params *params, va_list ap, char conv, char *arg)
{
	int		len;
	int		prec_padding;
	int		wid_padding;
	int		special;

	if (!(arg = get_u_arg(params, ap, conv, arg)))
		arg = ft_strdup("0");
	prec_padding = 0;
	if (ft_atoi(params->prec) >= (len = ft_strlen(arg)))
		prec_padding = ft_atoi(params->prec) - len;
	check_width_u(params, len, &wid_padding, prec_padding);
	special = 0;
	if (arg[0] == '0' && params->prec[0] != '\0' && ft_atoi(params->width))
		special += 1;
	if (arg[0] == '0' && params->prec[0] != '\0'
			&& !(ft_atoi(params->prec)))
	{
		ft_strdel(&arg);
		return (print_udecimal(params, "", 0, wid_padding + special));
	}
	return (print_udecimal(params, arg, prec_padding, wid_padding));
}
