/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_find_target.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 22:39:40 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/18 14:47:23 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			check_contact(t_data *d, t_move *cur, int x, int y)
{
	int		i;
	int		j;

	j = cur->backup_j;
	while (j < cur->limit_y)
	{
		i = cur->backup_i;
		x = d->piece->form_x;
		while (i < cur->limit_x)
		{
			if (d->piece->p[y][x] == '*')
			{
				cur->foe_count += count_contacts(d, i, j, d->ennemy);
				cur->ally_count += count_contacts(d, i, j, d->c);
				cur->void_count += count_contacts(d, i, j, '.');
				cur->border_count += count_borders(d, i, j, 0);
			}
			i += 1;
			x += 1;
		}
		j += 1;
		y += 1;
	}
	coefficialize(cur);
	return (cur->foe_count);
}

static int			can_place_near(t_data **data)
{
	int			result;
	t_move		*cur;
	t_data		*d;

	d = *data;
	cur = d->moves;
	result = 0;
	while (cur)
	{
		cur->backup_i = cur->x + d->piece->form_x;
		cur->backup_j = cur->y + d->piece->form_y;
		cur->limit_x = cur->backup_i + d->piece->form_wid + 1;
		cur->limit_y = cur->backup_j + d->piece->form_hei;
		if (check_contact(d, cur, 0, d->piece->form_y))
		{
			result += 1;
			cur->can_place_near = 1;
		}
		cur = cur->next;
	}
	return (result);
}

static void			find_centers(t_data *d, int i, int j)
{
	d->nb_turns += 1;
	calculate_my_middle(d, 0);
	while (j < d->grid_hei)
	{
		i = 0;
		while (i < d->grid_wid)
		{
			if (d->grid[j][i] == d->ennemy)
			{
				d->foe_total += 1;
				d->foe_count_x += i;
				d->foe_count_y += j;
			}
			else if (d->grid[j][i] == d->c)
			{
				d->my_total += 1;
				d->my_count_x += i;
				d->my_count_y += j;
			}
			i += 1;
		}
		j += 1;
	}
	calculate_my_middle(d, 1);
}

static t_move		*move_toward_ennemy(t_data *d, t_move **moves)
{
	t_move		*best;
	t_move		*mv;

	mv = *moves;
	best = mv;
	best->nearest_foe = find_nearest_foe(d, best, 0, 0);
	while (mv)
	{
		mv->nearest_foe = find_nearest_foe(d, mv, 0, 0);
		if (mv->nearest_foe < best->nearest_foe)
			best = mv;
		mv = mv->next;
	}
	return (best);
}

void				find_target(t_data *d)
{
	t_move		*best;

	find_centers(d, 0, 0);
	if ((d->can_place_near = can_place_near(&d)))
		best = circle_ennemy(d);
	else if (!d->contact)
		best = move_toward_ennemy(d, &(d->moves));
	else
		best = play_to_expand(d);
	d->x_answer = best->x;
	d->y_answer = best->y;
	d->last_x = d->x_answer + d->piece->form_x + d->piece->form_wid / 2;
	d->last_y = d->y_answer + d->piece->form_y + d->piece->form_hei / 2;
}
