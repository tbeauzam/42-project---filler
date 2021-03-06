/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:22:31 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/07 17:59:47 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char const *s, int fd)
{
	int		len;

	len = -1;
	if (s && fd != -1)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
	return (len);
}
