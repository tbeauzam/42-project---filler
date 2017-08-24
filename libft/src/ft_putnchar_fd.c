/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:32:29 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/16 17:38:53 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnchar_fd(char c, int fd, size_t n)
{
	int		len;

	len = 0;
	while (len < (int)n)
		len += ft_putchar_fd(c, fd);
	return (len);
}
