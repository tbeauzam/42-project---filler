/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_percent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:45:52 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/10 17:00:10 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_perc(t_params *p, int padding)
{
	if (ft_atoi(p->width) < 0 || ft_strchr(p->flags, '-'))
	{
		ft_putchar('%');
		ft_putnchar(' ', padding);
	}
	else
	{
		if (ft_strchr(p->flags, '0'))
			ft_putnchar('0', padding);
		else
			ft_putnchar(' ', padding);
		ft_putchar('%');
	}
	return (padding + 1);
}

int				handle_percent(t_params *params, va_list ap, char conv)
{
	int			len;
	int			padding;
	char		arg;

	len = 1;
	(void)conv;
	if (!(check_wildcard(&params, ap)))
		return (-1);
	arg = '%';
	padding = 0;
	if (len < ft_abs(ft_atoi(params->width)))
		padding = ft_abs(ft_atoi(params->width)) - len;
	return (print_perc(params, padding));
}
