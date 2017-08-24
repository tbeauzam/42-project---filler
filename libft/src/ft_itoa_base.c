/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:30:48 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/21 17:05:38 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_neg(long *nb, int base)
{
	int		neg;

	neg = 0;
	if (*nb < 0)
	{
		*nb *= -1;
		if (base == 10)
			neg = 1;
	}
	return (neg);
}

static char		*ft_convert(int value, int base, char *temp)
{
	int		i;
	int		neg;
	long	nb;

	i = 0;
	nb = value;
	neg = check_neg(&nb, base);
	while (nb > 0)
	{
		if (nb % base < 10)
			temp[i] = nb % base + '0';
		else
			temp[i] = nb % base + 'A' - 10;
		nb /= base;
		i += 1;
	}
	if (neg)
		temp[i] = '-';
	return (ft_strrev(temp));
}

char			*ft_itoa_base(int value, int base)
{
	char	*result;
	char	temp[35];

	result = NULL;
	ft_bzero(temp, sizeof(temp));
	if (value == 0)
		return (result = ft_strdup("0"));
	else
	{
		if (!(result = ft_strdup(ft_convert(value, base, temp))))
			return (NULL);
	}
	return (result);
}
