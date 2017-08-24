/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputnstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 02:18:24 by chkropok          #+#    #+#             */
/*   Updated: 2016/12/18 02:40:07 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wputnstr_fd(const wchar_t *s, int fd, size_t n)
{
	int		i;

	i = 0;
	if (s && fd != -1)
	{
		while (i < (int)n)
		{
			ft_wputchar_fd(s[i], fd);
			i += 1;
		}
	}
	return (i);
}
