/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:37:10 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/17 19:49:14 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wputstr_fd(const wchar_t *s, int fd)
{
	int		i;
	int		len;

	i = 0;
	len = -1;
	if (s && fd != -1)
	{
		len = ft_wstrlen(s);
		while (i < len)
		{
			ft_wputchar_fd(s[i], fd);
			i += 1;
		}
	}
	return (len);
}
