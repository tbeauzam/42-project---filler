/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr_base_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:55:42 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/21 12:58:46 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_zero(int nb, int fd)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	return (0);
}

static int		check_neg(long *nb)
{
	if (*nb < 0)
	{
		*nb *= -1;
		return (1);
	}
	return (0);
}

static void		put_minus(int *i, char *temp)
{
	temp[*i] = '-';
	*i += 1;
}

int				ft_putlongnbr_base_fd(long nb, int base, int fd)
{
	int		i;
	int		neg;
	char	temp[100];

	i = 0;
	if (check_zero(nb, fd))
		return (1);
	neg = check_neg(&nb);
	while (nb != 0)
	{
		if (nb % base < 10)
			temp[i] = nb % base + '0';
		else
			temp[i] = nb % base + 'a' - 10;
		nb /= base;
		i += 1;
	}
	if (neg)
		put_minus(&i, temp);
	temp[i] = '\0';
	ft_putstr_fd(ft_strrev(temp), fd);
	return (i);
}
