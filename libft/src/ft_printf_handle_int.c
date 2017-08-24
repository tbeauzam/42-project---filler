/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:09:40 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 12:37:15 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_d_arg(t_params *p, va_list ap, char conv, char *arg)
{
	unsigned int		temp;

	if (conv == 'D' || (ft_strchr("di", conv) && ft_strequ(p->size, "l")))
	{
		arg = ft_alltoa(va_arg(ap, unsigned long long));
		if ((temp = ft_atol(arg)) >= 0xffffffff || temp <= 0x80000000)
			return (arg);
		ft_strdel(&arg);
		return (arg = ft_alltoa(temp));
	}
	else if (ft_strequ(p->size, "hh"))
		return (arg = ft_alltoa((char)va_arg(ap, int)));
	else if (ft_strequ(p->size, "h"))
		return (arg = ft_alltoa((short)va_arg(ap, int)));
	else if (ft_strequ(p->size, "ll"))
		return (arg = ft_alltoa(va_arg(ap, unsigned long long)));
	else if (ft_strequ(p->size, "j"))
		return (arg = ft_alltoa(va_arg(ap, intmax_t)));
	else if (ft_strequ(p->size, "z"))
		return (arg = ft_alltoa(va_arg(ap, size_t)));
	if (ft_atol((arg = ft_alltoa(va_arg(ap, unsigned long long))))
			> 0xffffffff || ft_atol(arg) < 0x80000000)
		return (arg);
	arg = handle_that_delicate_case(&arg);
	return (arg);
}

static void		print_the_thing(t_params *p, char *s, int p_padd, int *len)
{
	if ((ft_strchr(p->flags, ' ') || ft_strchr(p->flags, '+'))
			&& s[0] != '-')
	{
		*len += 1;
		if (ft_strchr(p->flags, '+'))
			ft_putchar('+');
		else
			ft_putchar(' ');
	}
	if (s[0] == '-')
	{
		ft_putchar('-');
		s += 1;
	}
	ft_putnchar('0', p_padd);
	ft_putstr(s);
}

static int		print_decimal(t_params *p, char *s, int p_padd, int w_padd)
{
	int		len;

	len = ft_strlen(s);
	if (ft_atol(s) == 0 && p->prec[0] == '0')
		return (special_d_print(p, w_padd));
	else if (ft_atoi(p->width) < 0 || ft_strchr(p->flags, '-'))
	{
		if (w_padd < 0)
			w_padd = ft_abs(w_padd);
		print_the_thing(p, s, p_padd, &len);
		ft_putnchar(' ', ft_abs(w_padd));
	}
	else
	{
		if (ft_strchr(p->flags, '0') && !(ft_atoi(p->prec)))
			change_paddings_in_d(&p_padd, &w_padd);
		else
			ft_putnchar(' ', w_padd);
		print_the_thing(p, s, p_padd, &len);
	}
	ft_strdel(&s);
	return (len + p_padd + w_padd);
}

static int		handle_d(t_params *params, va_list ap, char conv, char *arg)
{
	int		len;
	int		prec_padding;
	int		wid_padding;
	int		special;

	if (!(arg = get_d_arg(params, ap, conv, arg)))
		arg = ft_strdup("0");
	check_prec_d(params, arg, &len, &prec_padding);
	check_width_d(params, arg, &prec_padding, &wid_padding);
	special = 0;
	if (arg[0] == '0' && params->prec[0] != '\0' && ft_atoi(params->width))
		special += 1;
	if (arg[0] == '0' && params->prec[0] != '\0'
			&& !(ft_atoi(params->prec)))
	{
		ft_strdel(&arg);
		return (print_decimal(params, "", 0, wid_padding + special));
	}
	return (print_decimal(params, arg, prec_padding, wid_padding));
}

int				handle_int(t_params *params, va_list ap, char conv)
{
	if (!(check_wildcard(&params, ap)))
		return (-1);
	if (ft_strchr("Ddi", conv))
		return (handle_d(params, ap, conv, NULL));
	else if (ft_strchr("oO", conv))
		return (handle_o(params, ap, conv, NULL));
	else if (ft_strchr("uU", conv))
		return (handle_u(params, ap, conv, NULL));
	else if (ft_strchr("xX", conv))
		return (handle_x(params, ap, conv, NULL));
	return (-1);
}
