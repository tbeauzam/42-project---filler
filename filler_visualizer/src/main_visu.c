/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:25:25 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 17:56:23 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static int		set_scores(t_data *d, char **line)
{
	char		*tmp;

	if (!(ft_strnstr(*line, "== O fin: ", 10)))
		return (0);
	tmp = ft_strchr(*line, ':') + 1;
	d->p1_score = ft_strtol(tmp, &tmp, 10);
	ft_strdel(line);
	if (d->nb_players == 2)
	{
		if (get_next_line(0, line) != 1)
			return (0);
		if (!(ft_strnstr(*line, "== X fin: ", 10)))
			return (0);
		tmp = ft_strchr(*line, ':') + 1;
		d->p2_score = ft_strtol(tmp, &tmp, 10);
	}
	return (1);
}

static int		get_info(char **line, t_data *d)
{
	char		*tmp;

	if (!ft_strnstr(*line, "launched ", 9) || ft_strstr(*line, "error:")
			|| !(tmp = ft_strchr(*line, ' ') + 1))
		return (0);
	d->p1_name = smooth_names(*line, ft_strlen(*line));
	ft_strdel(line);
	if (get_next_line(0, line) != 1 || ft_strstr(*line, "== ")
			|| ft_strstr(*line, "error:") || ft_strnstr(*line, "launched ", 9))
		return (0);
	ft_strdel(line);
	if (get_next_line(0, line) != 1)
		return (0);
	if (ft_strstr(*line, "launched "))
	{
		if (!(tmp = ft_strchr(*line, ' ') + 1))
			return (0);
		d->p2_name = smooth_names(*line, ft_strlen(*line));
		ft_strdel(line);
		if (get_next_line(0, line) != 1)
			return (0);
	}
	else
		d->nb_players = 1;
	return (1);
}

static t_data	*init_data(t_data *d)
{
	d = NULL;
	if (!(d = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	d->head = NULL;
	d->tail = NULL;
	d->cur = NULL;
	d->grid_wid = 0;
	d->grid_hei = 0;
	d->nb_players = 2;
	d->p1_name = NULL;
	d->p2_name = NULL;
	d->p1_alive = 1;
	d->p2_alive = 1;
	d->p1_score = 0;
	d->p2_score = 0;
	d->got = NULL;
	d->plateau_line = NULL;
	d->term_hei = 0;
	d->term_wid = 0;
	d->top = NULL;
	d->game = NULL;
	d->info = NULL;
	d->first_print = 0;
	return (d);
}

static int		handle_line(t_data *data, char **line)
{
	if (*line && (ft_strstr(*line, "launched ") || ft_strstr(*line, "error:")))
		if (!(get_info(line, data)))
			return (2);
	if (*line && ft_strstr(*line, "Plateau"))
		if (!get_current_state(&data, line))
			return (2);
	if (*line && (ft_strstr(*line, "Piece ") || ft_strstr(*line, "error")
	|| ft_strstr(*line, "Segfault at")))
		handle_death(&data, line);
	if (*line && (ft_strstr(*line, "<got ") || ft_strstr(*line, "Player with")))
		data->got = ft_strdup(*line);
	if (*line && ft_strstr(*line, "=="))
		if (!(set_scores(data, line)))
			return (2);
	if (*line)
		ft_strdel(line);
	if (data->head)
		if (!(loading_screen(&data, 0, 0)))
			return (3);
	if (data->head && !(check_for_avalaible_space(data)))
		return (4);
	return (0);
}

int				main(void)
{
	char	*line;
	t_data	*data;
	int		ret;

	line = NULL;
	if (!(data = init_data(NULL)))
		return (0);
	if (!(check_header(&line, 0)))
		return (print_error(data, 1));
	handle_visu();
	while (get_next_line(0, &line) == 1)
		if ((ret = handle_line(data, &line)))
			return (print_error(data, ret));
	data->tail = data->head;
	while (data->tail->next)
		data->tail = data->tail->next;
	data->tail->next = NULL;
	if (!handle_gui(data))
		return (print_error(data, 3));
	return (0);
}
