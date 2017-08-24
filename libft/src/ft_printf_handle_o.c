/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_o.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:41:52 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 12:29:18 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_o_arg(t_params *p, va_list ap, char conv, char *arg)
{
	if (conv == 'O' || (conv == 'o' && ft_strequ(p->size, "l")))
		return (arg = ft_alltoa_base(va_arg(ap, unsigned long), 8));
	else if (ft_strequ(p->size, "hh"))
		return (arg = ft_alltoa_base((unsigned char)va_arg(ap, int), 8));
	else if (ft_strequ(p->size, "h"))
		return (arg = ft_alltoa_base((unsigned short)va_arg(ap, int), 8));
	else if (ft_strequ(p->size, "ll"))
		return (arg = ft_alltoa_base(va_arg(ap, unsigned long long), 8));
	else if (ft_strequ(p->size, "j"))
		return (arg = ft_alltoa_base(va_arg(ap, uintmax_t), 8));
	else if (ft_strequ(p->size, "z"))
		return (arg = ft_alltoa_base(va_arg(ap, size_t), 8));
	return (arg = ft_alltoa_base(va_arg(ap, unsigned int), 8));
}

static int		print_the_thing2(t_params *p, char *s, int p_padd, int *w_padd)
{
	int		len;

	len = ft_strlen(s);
	if (ft_strchr(p->flags, '#'))
	{
		if (ft_abs(ft_atoi(p->width)) > len + p_padd + 1 && s[0] != '0')
		{
			*w_padd -= 1;
			ft_putnchar(' ', *w_padd);
		}
		else if (ft_abs(ft_atoi(p->width)) > len + p_padd + 2)
		{
			ft_putnchar(' ', *w_padd);
			len += 1;
			*w_padd -= 1;
		}
		if (!(ft_strequ(s, "0")))
		{
			len += 1;
			ft_putstr("0");
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
				ft_putstr("0");
		}
		ft_putnchar('0', *w_padd);
	}
	else
		len = print_the_thing2(p, s, *p_padd, w_padd);
	ft_putnchar('0', *p_padd);
	ft_putstr(s);
	return (len);
}

static int		print_octal(t_params *p, char *s, int p_padd, int w_padd)
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
				len += 1;
				ft_putstr("0");
				if (ft_abs(ft_atoi(p->width)) >= len + p_padd && s[0] != '0')
					w_padd -= 1;
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

int				handle_o(t_params *params, va_list ap, char conv, char *arg)
{
	int		len;
	int		prec_padding;
	int		wid_padding;
	int		special;

	if (!(arg = get_o_arg(params, ap, conv, arg)))
		arg = ft_strdup("0");
	prec_padding = 0;
	if (ft_atoi(params->prec) >= (len = ft_strlen(arg)))
		check_prec_o(params, arg, len, &prec_padding);
	check_width_o(params, len, &wid_padding, prec_padding);
	special = 0;
	if (arg[0] == '0' && params->prec[0] != '\0' && ft_atoi(params->width))
		special += 1;
	if (arg[0] == '0' && params->prec[0] != '\0'
			&& !(ft_atoi(params->prec)) && !(ft_strchr(params->flags, '#')))
	{
		ft_strdel(&arg);
		return (print_octal(params, "", prec_padding, wid_padding + special));
	}
	return (print_octal(params, arg, prec_padding, wid_padding));
}
