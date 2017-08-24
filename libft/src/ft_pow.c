/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:06:07 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/22 13:36:04 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_pow(int nb, int power)
{
	long	result;

	result = nb;
	if (power == 1)
		return (result);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		result *= nb;
		power -= 1;
	}
	return (result);
}
