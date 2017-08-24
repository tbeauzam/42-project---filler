/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:55 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/18 00:41:29 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		treat_char(wint_t c, unsigned char *bytes, int len)
{
	if (len < 12)
	{
		bytes[0] = 0xc0 | (c / ft_pow(2, 6));
		bytes[1] = 0x80 | (c % ft_pow(2, 6));
	}
	else if (len < 17)
	{
		bytes[0] = 0xe0 | (c / ft_pow(2, 12));
		c %= ft_pow(2, 12);
		bytes[1] = 0x80 | (c / ft_pow(2, 6));
		bytes[2] = 0x80 | (c % ft_pow(2, 6));
	}
	else if (len < 22)
	{
		bytes[0] = 0xf0 | (c / ft_pow(2, 18));
		c %= ft_pow(2, 18);
		bytes[1] = 0x80 | (c / ft_pow(2, 12));
		c %= ft_pow(2, 12);
		bytes[2] = 0x80 | (c / ft_pow(2, 6));
		bytes[3] = 0x80 | (c % ft_pow(2, 6));
	}
}

int				ft_wputchar_fd(wint_t c, int fd)
{
	unsigned char	bytes[5];
	char			*temp;
	int				i;

	temp = NULL;
	ft_bzero(bytes, sizeof(bytes));
	i = 0;
	if (c < (wint_t)ft_pow(2, 7))
		return (ft_putchar_fd(c, fd));
	else if (c >= 0xd800 && c <= 0xdfff)
		return (3);
	else
	{
		temp = ft_itoa_base(c, 2);
		treat_char(c, bytes, ft_strlen(temp));
		ft_strdel(&temp);
		while (bytes[i] != 0)
		{
			ft_putchar_fd(bytes[i], fd);
			i += 1;
		}
		return (i);
	}
}
