/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_circling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 22:57:18 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/20 19:14:05 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_move			*play_to_expand(t_data *d)
{
	int			dest_x;
	int			dest_y;
	t_move		*best;
	t_move		*mv;

	mv = d->moves;
	best = mv;
	dest_x = d->last_x;
	dest_y = d->last_y;
	while (mv)
	{
		if (d->occupation < 0.4)
		{
			if (((ft_max(dest_y, mv->y) - ft_min(dest_y, mv->y))
					+ (ft_max(dest_x, mv->x) - ft_min(dest_x, mv->x)))
					< ((ft_max(dest_y, best->y) - ft_min(dest_y, best->y))
					+ (ft_max(dest_x, best->x) - ft_min(dest_x, best->x))))
				best = mv;
		}
		else if (mv->void_count < best->void_count)
			best = mv;
		mv = mv->next;
	}
	return (best);
}

static t_move	*find_best_move_with_contact(t_data *d)
{
	t_move		*first;
	t_move		*best;

	first = d->moves;
	best = first;
	while (first)
	{
		first->void_count += can_expand
(d, (first->x + d->piece->form_x), (first->y + d->piece->form_y));
		if (first->foe_count)
			first->diff_count = first->foe_count + first->void_count +
first->border_count - first->ally_count;
		if (!best->foe_count && first->foe_count)
			best = first;
		if (first->diff_count > best->diff_count)
			best = first;
		first = first->next;
	}
	return (best);
}

t_move			*circle_ennemy(t_data *d)
{
	int			dest_x;
	int			dest_y;
	t_move		*best;
	t_move		*mv;

	d->contact = 1;
	mv = d->moves;
	if (!(best = find_best_move_with_contact(d)))
		return (NULL);
	dest_x = d->last_x;
	dest_y = d->last_y;
	while (mv)
	{
		if (mv->diff_count == best->diff_count
				&& ((ft_max(dest_y, mv->y) - ft_min(dest_y, mv->y))
				+ (ft_max(dest_x, mv->x) - ft_min(dest_x, mv->x)))
				< ((ft_max(dest_y, best->y) - ft_min(dest_y, best->y))
				+ (ft_max(dest_x, best->x) - ft_min(dest_x, best->x))))
			best = mv;
		mv = mv->next;
	}
	return (best);
}
