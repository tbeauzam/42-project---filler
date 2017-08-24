/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_current_state.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 10:33:19 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/20 17:50:17 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static int			last_input(t_data *d)
{
	d->tail->got = ft_strdup(d->got);
	if (d->tail->prev)
	{
		d->tail->p1_score = d->tail->prev->p1_score;
		d->tail->p2_score = d->tail->prev->p2_score;
		if (ft_strstr(d->tail->got, "O") && d->p1_alive)
			d->tail->p1_score += 1;
		if (ft_strstr(d->tail->got, "X") && d->p2_alive)
			d->tail->p2_score += 1;
	}
	ft_strdel(&(d->got));
	return (1);
}

t_state				*create_state(t_data *d)
{
	t_state		*new;

	new = NULL;
	if (!(new = (t_state *)malloc(sizeof(t_state))))
		return (NULL);
	new->id = 1;
	new->p1_alive = d->p1_alive;
	new->p2_alive = d->p2_alive;
	new->p1_score = 0;
	new->p2_score = 0;
	if (d->tail)
	{
		new->p1_score = d->tail->p1_score;
		new->p2_score = d->tail->p2_score;
	}
	new->grid = NULL;
	new->piece = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->got = NULL;
	return (new);
}

static int			get_state(t_data *d, char **line)
{
	t_state		*new;

	if (!(new = create_state(d)))
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
		d->tail = new;
	}
	if (!(new->grid = read_grid(d, line)))
		return (0);
	if (!(new->piece = read_piece(line, 0)))
		return (0);
	if (d->got)
		last_input(d);
	return (1);
}

static int			get_grid_info(t_data **data, char **line)
{
	t_data		*d;
	char		*tmp;

	d = *data;
	if (!(ft_strnstr(*line, "Plateau ", 8)))
		return (0);
	tmp = *line;
	tmp = ft_strchr(tmp, ' ');
	if (!(d->grid_hei = ft_strtol(tmp, &tmp, 10)))
		return (0);
	if (tmp[0] != ' ' || !(d->grid_wid = ft_strtol(tmp, NULL, 10)))
		return (0);
	return (1);
}

int					get_current_state(t_data **data, char **line)
{
	t_data		*d;

	d = *data;
	if (!chk_plateau_line(d, *line))
		return (0);
	if (!d->head)
		if (!(get_grid_info(data, line)))
			return (0);
	if (*line)
		ft_strdel(line);
	waste_next_line(line);
	if (!(get_state(d, line)))
		return (0);
	return (1);
}
