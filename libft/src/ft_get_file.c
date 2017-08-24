/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:54:34 by chkropok          #+#    #+#             */
/*   Updated: 2017/01/16 01:21:02 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_get_file(char *filename)
{
	int		fd;
	int		ret;
	int		len;
	char	*result;
	char	buffer[100001];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	len = 0;
	while ((ret = read(fd, buffer, 100000)))
		len += ret;
	close(fd);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	read(fd, result, len);
	result[len] = '\0';
	close(fd);
	return (result);
}
