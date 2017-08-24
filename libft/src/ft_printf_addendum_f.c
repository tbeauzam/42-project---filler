/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addendum_f.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:30:42 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 15:33:00 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		savage_incrementation(int *i, int len)
{
	if (len)
		*i += len;
	else
		*i += 1;
}

void		check_wp_p(t_params *params, int *len, int *p_padd, int *w_padd)
{
	*p_padd = 0;
	if (ft_atoi(params->prec) > *len)
		*p_padd = ft_atoi(params->prec) - *len;
	*w_padd = 0;
	if (ft_abs(ft_atoi(params->width)) > *len + *p_padd + 2)
		*w_padd = ft_abs(ft_atoi(params->width)) - (*len + *p_padd + 2);
}

void		check_prec_d(t_params *params, char *arg, int *len, int *p_padd)
{
	*p_padd = 0;
	if (ft_atoi(params->prec) >= (*len = ft_strlen(arg)))
	{
		*p_padd = ft_atoi(params->prec) - *len;
		if (arg[0] == '-')
			*p_padd += 1;
	}
}

t_list2		*create_lstd(const void *content, size_t content_size)
{
	t_list2		*elem;
	char		*s;

	if (!(elem = (t_list2 *)malloc(sizeof(t_list2))))
		return (NULL);
	else
	{
		s = NULL;
		elem->next = NULL;
		if (!content)
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		else
		{
			if (!(s = ft_strdup(content)))
				return (NULL);
			elem->content = s;
			elem->content_size = content_size;
		}
	}
	return (elem);
}

void		lstdadd_back(t_list2 **alst, t_list2 *new_elem)
{
	t_list2		*temp;

	temp = *alst;
	if (!temp)
		temp = new_elem;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_elem;
	}
}
