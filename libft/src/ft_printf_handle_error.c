/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:06:40 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/11 17:43:34 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_thing(t_params *p, int padding, char conv)
{
	if (ft_atoi(p->width) < 0 || ft_strchr(p->flags, '-'))
	{
		ft_putchar(conv);
		ft_putnchar(' ', padding);
	}
	else
	{
		if (ft_strchr(p->flags, '0'))
			ft_putnchar('0', padding);
		else
			ft_putnchar(' ', padding);
		ft_putchar(conv);
	}
	return (padding + 1);
}

int				handle_error(t_params *params, va_list ap, char conv)
{
	int			len;
	int			padding;
	char		arg;

	if (conv == '%' || (ft_strchr(FLAG_LIST, conv)))
		return (0);
	len = 1;
	if (!(check_wildcard(&params, ap)))
		return (-1);
	arg = conv;
	padding = 0;
	if (len < ft_abs(ft_atoi(params->width)))
		padding = ft_abs(ft_atoi(params->width)) - len;
	return (print_thing(params, padding, conv));
}
