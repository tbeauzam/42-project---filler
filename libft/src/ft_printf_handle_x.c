/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:22:43 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 12:19:00 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_x_arg(t_params *p, va_list ap, char *arg)
{
	if (ft_strequ(p->size, "hh"))
		return (arg = ft_alltoa_base((unsigned char)va_arg(ap, int), 16));
	else if (ft_strequ(p->size, "h"))
		return (arg = ft_alltoa_base((unsigned short)va_arg(ap, int), 16));
	else if (ft_strequ(p->size, "l"))
		return (arg = ft_alltoa_base(va_arg(ap, unsigned long), 16));
	else if (ft_strequ(p->size, "ll"))
		return (arg = ft_alltoa_base(va_arg(ap, unsigned long long), 16));
	else if (ft_strequ(p->size, "j"))
		return (arg = ft_alltoa_base(va_arg(ap, uintmax_t), 16));
	else if (ft_strequ(p->size, "z"))
		return (arg = ft_alltoa_base(va_arg(ap, size_t), 16));
	return (arg = ft_alltoa_base(va_arg(ap, unsigned int), 16));
}

static int		print_the_thing2(t_params *p, char *s, int p_padd, int *w_padd)
{
	int		len;

	len = ft_strlen(s);
	if (ft_strchr(p->flags, '#'))
	{
		if (ft_abs(ft_atoi(p->width)) > len + p_padd + 2 && s[0] != '0')
		{
			*w_padd -= 2;
			ft_putnchar(' ', *w_padd);
		}
		else if (ft_abs(ft_atoi(p->width)) > len + p_padd + 2)
		{
			ft_putnchar(' ', *w_padd);
			len += 2;
			*w_padd -= 2;
		}
		if (!(ft_strequ(s, "0")))
		{
			len += 2;
			ft_putstr("0x");
		}
	}
	else
		ft_putnchar(' ', *w_padd);
	return (len);
}

static int		print_the_thing(t_params *p, char *s, int *p_padd, int *w_padd)
{
	int		len;

	len = ft_strlen(s);
	if (ft_strchr(p->flags, '0') && p->prec[0] == '\0')
	{
		if (ft_strchr(p->flags, '#'))
		{
			if (!(ft_strequ(s, "0")))
			{
				ft_putstr("0x");
				if (ft_atoi(p->width) > len)
					*w_padd -= 2;
				len += 2;
			}
		}
		ft_putnchar('0', *w_padd);
	}
	else
		len = print_the_thing2(p, s, *p_padd, w_padd);
	ft_putnchar('0', *p_padd);
	ft_putstr(s);
	return (len);
}

static int		print_hexa(t_params *p, char *s, int p_padd, int w_padd)
{
	int		len;

	len = ft_strlen(s);
	ft_lower_str(s);
	if (s[0] == '0' && p->width[0] == '\0' && p->prec[0] == '\0')
		ft_putchar('0');
	else if (ft_atoi(p->width) < 0 || ft_strchr(p->flags, '-'))
	{
		if (ft_strchr(p->flags, '#'))
		{
			if (!(ft_strequ(s, "0")))
			{
				len += 2;
				ft_putstr("0x");
				if (ft_abs(ft_atoi(p->width)) > len + p_padd + 2 && s[0] != '0')
					w_padd -= 2;
			}
		}
		print_that_thing(s, p_padd, w_padd);
	}
	else
		len = print_the_thing(p, s, &p_padd, &w_padd);
	if (ft_strlen(s))
		ft_strdel(&s);
	return (len + w_padd + p_padd);
}

int				handle_x(t_params *params, va_list ap, char conv, char *arg)
{
	int		len;
	int		prec_padding;
	int		wid_padding;
	int		special;

	if (!(arg = get_x_arg(params, ap, arg)))
		arg = ft_strdup("0");
	if (conv == 'X')
		return (handle_uppercase_x(params, arg));
	prec_padding = 0;
	if (ft_atoi(params->prec) >= (len = ft_strlen(arg)))
		prec_padding = ft_atoi(params->prec) - len;
	check_width_x(params, len, &prec_padding, &wid_padding);
	special = 0;
	if (arg[0] == '0' && params->prec[0] != '\0' && ft_atoi(params->width))
		special += 1;
	if (arg[0] == '0' && params->prec[0] != '\0'
			&& !(ft_atoi(params->prec)))
	{
		params->flags = ft_str_remc(params->flags, '#');
		ft_strdel(&arg);
		return (print_hexa(params, "", prec_padding, wid_padding + special));
	}
	return (print_hexa(params, arg, prec_padding, wid_padding));
}
