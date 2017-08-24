/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_grid_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:31:24 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/18 10:38:54 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		chk_place(t_data *d, int x, int y, int check)
{
	int			i;
	int			j;
	int			backup_x;

	backup_x = x;
	j = d->piece->form_y;
	while (j < d->piece->form_y + d->piece->form_hei)
	{
		x = backup_x;
		i = d->piece->form_x;
		while (i < d->piece->form_x + d->piece->form_wid)
		{
			if (d->piece->p[j][i] == '*' && d->grid[y][x] == d->c)
				check += 1;
			else if (d->piece->p[j][i] == '*' && d->grid[y][x] != '.')
				return (0);
			x += 1;
			i += 1;
		}
		y += 1;
		j += 1;
	}
	return ((check == 1) ? 1 : 0);
}

static t_move	*init_move(int x, int y)
{
	t_move		*new;

	new = NULL;
	if (!(new = (t_move *)malloc(sizeof(t_move))))
		return (NULL);
	new->next = NULL;
	new->x = x;
	new->y = y;
	new->foe_count = 0;
	new->ally_count = 0;
	new->void_count = 0;
	new->nearest_foe = 0;
	new->border_count = 0;
	new->diff_count = 0;
	new->can_place_near = 0;
	return (new);
}

static int		add_to_list(t_move **moves, int x, int y)
{
	t_move		*new;
	t_move		*temp;

	new = NULL;
	if (!(new = init_move(x, y)))
		return (0);
	temp = *moves;
	if (!temp)
		*moves = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

t_move			*list_moves(t_data *d, int x, int y)
{
	t_move		*moves;
	int			backup_x;

	backup_x = x;
	moves = NULL;
	while (y <= (d->grid_hei - (d->piece->form_hei + d->piece->form_y)))
	{
		x = backup_x;
		while (x <= (d->grid_wid - (d->piece->form_wid + d->piece->form_x)))
		{
			if (chk_place
(d, (x + d->piece->form_x), (y + d->piece->form_y), 0))
				if (!(add_to_list(&moves, x, y)))
					return (NULL);
			x += 1;
		}
		y += 1;
	}
	return (moves);
}

int				find_the_best_place(t_data *d)
{
	t_move		*moves;

	moves = list_moves(d, (0 - d->piece->form_x), (0 - d->piece->form_y));
	if (!moves)
		return (0);
	else
	{
		d->moves = moves;
		find_target(d);
		return (1);
	}
}
