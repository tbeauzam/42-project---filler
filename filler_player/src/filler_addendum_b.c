/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_addendum_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:20:51 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/18 16:58:33 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				count_borders(t_data *d, int i, int j, int result)
{
	if (i == 0 || i == d->grid_wid - 1 || i == 1 || i == d->grid_wid - 2
			|| j == 0 || j == d->grid_hei - 1 || j == 1 || j == d->grid_hei - 2)
		result = 3;
	return (result);
}

static int		ponder(t_data *d, int result, int x, int y)
{
	if ((d->my_middle_x < (d->grid_wid / 2) && x < d->my_middle_x)
			|| (d->my_middle_x > (d->grid_wid / 2) && x > d->my_middle_x))
		result /= 10;
	if ((d->my_middle_y < (d->grid_hei / 2) && y < d->my_middle_y)
			|| (d->my_middle_y > (d->grid_hei / 2) && y > d->my_middle_y))
		result /= 10;
	return (result);
}

static int		line_is_empty(t_data *d, int line)
{
	int		i;

	i = 0;
	while (i < d->grid_wid)
	{
		if (d->grid[line][i] == d->c)
			return (0);
		i += 1;
	}
	return (1);
}

static int		col_is_empty(t_data *d, int col)
{
	int		i;

	i = 0;
	while (i < d->grid_hei)
	{
		if (d->grid[i][col] == d->c)
			return (0);
		i += 1;
	}
	return (1);
}

int				can_expand(t_data *d, int x, int y)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (i < d->piece->form_wid)
	{
		if (col_is_empty(d, x + i))
			result += 10;
		i += 1;
	}
	i = 0;
	while (i < d->piece->form_hei)
	{
		if (line_is_empty(d, y + i))
			result += 10;
		i += 1;
	}
	result = ponder(d, result, x, y);
	return (result / 2);
}
