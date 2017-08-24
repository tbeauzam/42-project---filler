/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:13:36 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 11:55:24 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_wide_char(t_params *params, wint_t c, int len, int pad)
{
	if (ft_atoi(params->width) < 0 || ft_strchr(params->flags, '-'))
	{
		ft_wputchar(c);
		ft_putnchar(' ', pad);
	}
	else
	{
		if (ft_strchr(params->flags, '0'))
			ft_putnchar('0', pad);
		else
			ft_putnchar(' ', pad);
		ft_wputchar(c);
	}
	return (len + pad);
}

static int		print_char(t_params *params, char c, int len, int padding)
{
	if (ft_atoi(params->width) < 0 || ft_strchr(params->flags, '-'))
	{
		ft_putchar(c);
		ft_putnchar(' ', padding);
	}
	else
	{
		if (ft_strchr(params->flags, '0'))
			ft_putnchar('0', padding);
		else
			ft_putnchar(' ', padding);
		ft_putchar(c);
	}
	return (len + padding);
}

static int		handle_lc(t_params *params, va_list ap, int len)
{
	int		count;
	int		padding;
	wint_t	arg;

	if (!(arg = va_arg(ap, int)))
		arg = 0;
	len = inc_char_len(arg);
	padding = 0;
	if (len < ft_abs(ft_atoi(params->width)))
		padding = ft_abs(ft_atoi(params->width)) - len;
	return (count = print_wide_char(params, arg, len, padding));
}

int				handle_c(t_params *params, va_list ap, char conv)
{
	int			len;
	int			padding;
	char		arg;

	len = 1;
	if (!(check_wildcard(&params, ap)))
		return (-1);
	if (conv == 'C' || (conv == 'c' && ft_strequ(params->size, "l")))
		return (handle_lc(params, ap, len));
	arg = (va_arg(ap, int));
	padding = 0;
	if (len < ft_abs(ft_atoi(params->width)))
		padding = ft_abs(ft_atoi(params->width)) - len;
	return (print_char(params, arg, len, padding));
}
