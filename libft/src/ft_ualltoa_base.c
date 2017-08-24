/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ualltoa_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:58:16 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/06 17:03:10 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert(unsigned long long nb, int base, char *temp)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		if (nb % base < 10)
			temp[i] = nb % base + '0';
		else
			temp[i] = nb % base + 'A' - 10;
		nb /= base;
		i += 1;
	}
	return (ft_strrev(temp));
}

char			*ft_ualltoa_base(unsigned long long nb, int base)
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
