/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:21:17 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/17 18:19:38 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc_base(char c)
{
	int value;

	value = -1;
	if (ft_isdigit(c))
		value = c - '0';
	else if (ft_isupper(c))
		value = c - 'A' + 10;
	else
		value = c - 'a' + 10;
	return (value);
}

static void		misc_checks(const char *s, int *i, int *base, int *neg)
{
	while (s[*i] > 0 && s[*i] <= 32)
		*i += 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			*neg *= -1;
		*i += 1;
	}
	if (((*base == 16 && s[*i] == '0' && (s[*i + 1] == 'x' || s[*i + 1] == 'X'))
			|| (*base == 0 && s[*i] == '0'
			&& (s[*i + 1] == 'x' || s[*i + 1] == 'X'))))
	{
		*base = 16;
		*i += 2;
	}
	if (*base == 0 && s[*i] == '0')
		*base = 8;
	if (*base == 0)
		*base = 10;
}

long			ft_strtol(const char *s, char **endptr, int base)
{
	long	nb;
	int		neg;
	int		i;
	int		value;

	nb = 0;
	neg = -1;
	i = 0;
	misc_checks(s, &i, &base, &neg);
	while (s[i] && ((value = calc_base(s[i])) >= 0 && value < base))
	{
		nb *= base;
		if (ft_isdigit(s[i]))
			nb -= (s[i] - '0');
		else if (ft_isupper(s[i]))
			nb -= (s[i] - 'A' + 10);
		else
			nb -= (s[i] - 'a' + 10);
		i += 1;
	}
	nb *= neg;
	if (endptr)
		*endptr += i;
	return (nb);
}
