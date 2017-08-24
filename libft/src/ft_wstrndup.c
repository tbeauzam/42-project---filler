/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 01:17:13 by chkropok          #+#    #+#             */
/*   Updated: 2016/12/18 01:28:19 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrndup(const wchar_t *s, size_t n)
{
	size_t		i;
	wchar_t		*result;

	if (!(result = (wchar_t *)malloc((n + 1) * sizeof(wint_t))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i += 1;
	}
	result[i] = '\0';
	return (result);
}
