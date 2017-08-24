/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:13:31 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/06 13:02:31 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_ls_arg(t_params *params, wchar_t *s, int len, int padd)
{
	int		char_lens;
	int		nothing;

	nothing = 0;
	char_lens = wchar_len(s, &nothing, params->prec);
	if (ft_atoi(params->width) < 0 || ft_strchr(params->flags, '-'))
	{
		ft_wputnstr(s, len);
		ft_putnchar(' ', padd);
	}
	else
	{
		if (ft_strchr(params->flags, '0'))
			ft_putnchar('0', padd);
		else
			ft_putnchar(' ', padd);
		ft_wputnstr(s, len);
	}
	return (char_lens + padd);
}

static int		print_s_arg(t_params *params, char *s, int len, int padding)
{
	if (ft_atoi(params->width) < 0 || ft_strchr(params->flags, '-'))
	{
		ft_putnstr(s, len);
		ft_putnchar(' ', padding);
	}
	else
	{
		if (ft_strchr(params->flags, '0'))
			ft_putnchar('0', padding);
		else
			ft_putnchar(' ', padding);
		ft_putnstr(s, len);
	}
	return (len + padding);
}

static int		handle_ls(t_params *params, va_list ap)
{
	int			len;
	int			padding;
	int			real_len;
	wchar_t		*arg;

	if (!(check_wildcard(&params, ap)))
		return (-1);
	if (!(arg = va_arg(ap, wchar_t *)))
	{
		arg = L"(null)";
		len = ft_wstrlen(arg);
		if ((len > ft_atoi(params->prec) && params->prec[0] != '\0'))
			len = ft_atoi(params->prec);
		padding = 0;
		if (len < ft_atoi(params->width))
			padding = ft_atoi(params->width) - len;
		return (print_s_arg(params, "(null)", len, padding));
	}
	real_len = 0;
	len = wchar_len(arg, &real_len, params->prec);
	padding = 0;
	if (len < ft_abs(ft_atoi(params->width)))
		padding = ft_abs(ft_atoi(params->width)) - len;
	return (print_ls_arg(params, arg, real_len, padding));
}

int				handle_s(t_params *params, va_list ap, char conv)
{
	int			len;
	int			count;
	int			padding;
	char		*arg;

	if (!(check_wildcard(&params, ap)))
		return (-1);
	if (conv == 'S' || ft_strequ(params->size, "l"))
		return (count = handle_ls(params, ap));
	if (!(arg = (va_arg(ap, char *))))
		arg = "(null)";
	if ((len = ft_strlen(arg)) > ft_atoi(params->prec) && params->prec[0] != 0)
		len = ft_atoi(params->prec);
	padding = 0;
	if (len < ft_abs(ft_atoi(params->width)))
		padding = ft_abs(ft_atoi(params->width)) - len;
	count = print_s_arg(params, arg, len, padding);
	return (count);
}
