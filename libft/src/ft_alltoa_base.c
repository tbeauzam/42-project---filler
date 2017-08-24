/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:25:55 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/22 13:57:01 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_neg(unsigned long long *nb, int base)
{
	if (base == 10)
	{
		if (*nb == 0x8000000000000000)
			return (1);
		if (*nb > (unsigned long long)ft_pow(2, 63))
		{
			*nb *= -1;
			return (1);
		}
	}
	return (0);
}

static char		*ft_convert(unsigned long long nb, int base, char *temp)
{
	int		i;
	int		neg;

	i = 0;
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

char			*ft_alltoa_base(unsigned long long nb, int base)
{
	char	*result;
	char	temp[100];

	result = NULL;
	ft_bzero(temp, sizeof(temp));
	if (nb == 0)
		return (result = ft_strdup("0"));
	else
	{
		if (!(result = ft_strdup(ft_convert(nb, base, temp))))
			return (NULL);
	}
	return (result);
}
