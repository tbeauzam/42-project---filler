/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:02:46 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/09 17:09:02 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(char const *str)
{
	unsigned long	nb;
	int				neg;
	int				i;

	nb = 0;
	neg = -1;
	i = 0;
	while (str[i] > 0 && str[i] <= 32)
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i += 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb -= (str[i] - '0');
		i += 1;
	}
	nb *= neg;
	return (nb);
}
