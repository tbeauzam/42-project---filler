/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_addendum_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:53:50 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 19:13:48 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			coefficialize(t_move *cur)
{
	cur->foe_count *= COEFF_FOE;
	cur->ally_count *= COEFF_ALLY;
	cur->void_count *= COEFF_VOID;
}

void			calculate_my_middle(t_data *d, int mode)
{
	int		size;

	size = (d->grid_hei * d->grid_wid == 0 ? 1 : d->grid_hei * d->grid_wid);
	if (mode)
	{
		d->foe_total = ((d->foe_total == 0) ? 1 : d->foe_total);
		d->foe_middle_x = d->foe_count_x / d->foe_total;
		d->foe_middle_y = d->foe_count_y / d->foe_total;
		d->my_total = ((d->my_total == 0) ? 1 : d->my_total);
		d->my_middle_x = d->my_count_x / d->my_total;
		d->my_middle_y = d->my_count_y / d->my_total;
		d->occupation =
((double)(d->my_total) + (double)(d->foe_total)) / (double)(size);
	}
	else
	{
		d->foe_total = 0;
		d->foe_count_x = 0;
		d->foe_count_y = 0;
		d->my_total = 0;
		d->my_count_x = 0;
		d->my_count_y = 0;
	}
}

static int		calculate_distance(t_data *d, t_move *cur, int i, int j)
{
	int		result;
	int		middle_form_x;
	int		middle_form_y;

	middle_form_x = d->piece->piece_wid / 2 + d->piece->form_x + cur->x;
	middle_form_y = d->piece->piece_hei / 2 + d->piece->form_y + cur->y;
	result = ft_max(i, middle_form_x) - ft_min(i, middle_form_x) +
ft_max(j, middle_form_y) - ft_min(j, middle_form_y);
	return (result);
}

int				find_nearest_foe(t_data *d, t_move *cur, int i, int j)
{
	int		result;
	int		best;

	best = -1;
	while (j < d->grid_hei)
	{
		i = 0;
		result = -1;
		while (i < d->grid_wid)
		{
			if (d->grid[j][i] == d->ennemy)
				result = calculate_distance(d, cur, i, j);
			if ((best == -1 && result != -1)
					|| (result != -1 && best != -1 && result < best))
				best = result;
			i += 1;
		}
		j += 1;
	}
	return (best);
}

int				count_contacts(t_data *d, int i, int j, char target)
{
	int		result;

	result = 0;
	if (i - 1 >= 0 && j - 1 >= 0 && d->grid[j - 1][i - 1] == target)
		result += 1;
	if (j - 1 >= 0 && d->grid[j - 1][i] == target)
		result += 1;
	if (i + 1 < d->grid_wid && j - 1 >= 0 && d->grid[j - 1][i + 1] == target)
		result += 1;
	if (i - 1 >= 0 && d->grid[j][i - 1] == target)
		result += 1;
	if (i + 1 < d->grid_wid && d->grid[j][i + 1] == target)
		result += 1;
	if (i - 1 >= 0 && j + 1 < d->grid_hei && d->grid[j + 1][i - 1] == target)
		result += 1;
	if (j + 1 < d->grid_hei && d->grid[j + 1][i] == target)
		result += 1;
	if (i + 1 < d->grid_wid && j + 1 < d->grid_hei
			&& d->grid[j + 1][i + 1] == target)
		result += 1;
	return (result);
}
