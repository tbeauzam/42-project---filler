/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:09:17 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/07 17:06:05 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int		len;

	len = -1;
	if (s && fd != -1)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		ft_putchar_fd('\n', fd);
	}
	return (len);
}
