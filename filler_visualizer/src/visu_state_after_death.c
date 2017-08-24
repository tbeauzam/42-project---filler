/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_state_after_death.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:32:22 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 19:08:00 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

int					check_header(char **line, int i)
{
	while (i < 5)
	{
		if (get_next_line(0, line) != 1)
			return (0);
		if (ft_strlen(*line) != 48)
			return (0);
		ft_strdel(line);
		i += 1;
	}
	return (1);
}

static int			last_input(t_data *d)
{
	d->tail->got = ft_strdup(d->got);
	if (d->tail)
	{
		if (d->tail->prev)
		{
			d->tail->p1_score = d->tail->prev->p1_score;
			d->tail->p2_score = d->tail->prev->p2_score;
		}
		if (ft_strstr(d->tail->got, "O"))
		{
			d->p1_alive = 0;
			d->tail->p1_alive = 0;
		}
		if (ft_strstr(d->tail->got, "X"))
		{
			d->p2_alive = 0;
			d->tail->p2_alive = 0;
		}
	}
	ft_strdel(&(d->got));
	return (1);
}

static int			get_state(t_data *d, char **line)
{
	t_state		*new;

	if (!(new = create_state(d)))
		return (0);
	if (!(new->piece = read_piece(line, 0)))
		return (0);
	if (!d->head)
	{
		d->head = new;
		d->tail = new;
	}
	else
	{
		d->tail->next = new;
		new->prev = d->tail;
		new->id += d->tail->id;
		new->grid = d->tail->grid;
		d->tail = new;
	}
	if (d->got)
		last_input(d);
	return (1);
}

int					handle_death(t_data **data, char **line)
{
	t_data		*d;

	d = *data;
	get_state(d, line);
	return (1);
}
