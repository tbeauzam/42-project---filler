/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:54:29 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/16 16:14:30 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr_fd(const char *s, int fd, size_t n)
{
	int		len;

	len = -1;
	if (s && fd != -1)
	{
		len = ft_strlen(s);
		if ((int)n < len)
			len = n;
		write(fd, s, len);
	}
	return (len);
}
