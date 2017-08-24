/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:35:31 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 14:21:02 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

int					print_error(t_data *d, int code)
{
	if (code == 1)
		ft_putendl_fd("error: bad input", 2);
	if (code >= 2)
	{
		clear();
		refresh();
		endwin();
		if (code == 2)
			ft_putendl_fd("error while processing", 2);
		if (code == 3)
			ft_putendl_fd("please do not resize term during execution", 2);
		if (code == 4)
		{
			ft_putendl_fd("error: not enough space in terminal\nCurrent: ", 2);
			ft_putnbr_fd(d->term_hei, 2);
			ft_putendl_fd(" x ", 2);
			ft_putnbr_fd(d->term_wid, 2);
			ft_putendl_fd("\nMinimum needed : ", 2);
			ft_putnbr_fd(d->grid_hei + 21, 2);
			ft_putstr_fd(" x ", 2);
			ft_putnbr_fd((d->grid_wid < 58 ? 120 : d->grid_wid * 2 + 6), 2);
			ft_putendl_fd("", 2);
		}
	}
	return (code);
}

static t_piece		*create_piece(int hei, int wid)
{
	t_piece		*new;

	new = NULL;
	if (!(new = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	new->p = NULL;
	new->piece_wid = wid;
	new->piece_hei = hei;
	new->form_x = 0;
	new->form_y = 0;
	new->form_wid = 0;
	new->form_hei = 0;
	return (new);
}

static char			**get_piece_lines(t_piece *new, int i, char **line)
{
	char		**grid;

	grid = NULL;
	if (!(grid = (char **)malloc(sizeof(char *) * (new->piece_hei + 1))))
		return (NULL);
	grid[new->piece_hei] = NULL;
	while (i < new->piece_hei)
	{
		if (get_next_line(0, line) != 1)
			return (NULL);
		if ((int)ft_strlen(*line) != new->piece_wid)
			return (NULL);
		grid[i] = ft_strdup(*line);
		ft_strdel(line);
		i += 1;
	}
	if (get_next_line(0, line) != 1)
		return (NULL);
	if (ft_strchr(*line, '*') || ft_strchr(*line, '.'))
		return (NULL);
	return (grid);
}

t_piece				*read_piece(char **line, int i)
{
	t_piece		*new;
	char		*t;

	if (!(*line))
		get_next_line(0, line);
	if (!(chk_piece_line(*line)))
		return (NULL);
	t = ft_strchr(*line, ' ');
	if (!(new = create_piece(ft_strtol(t, &t, 10), ft_strtol(t, &t, 10))))
		return (NULL);
	ft_strdel(line);
	if (!(new->p = get_piece_lines(new, i, line)))
		return (0);
	return (new);
}

char				**read_grid(t_data *d, char **line)
{
	char		**grid;
	char		*tmp;
	int			i;

	grid = NULL;
	if (!(grid = (char **)malloc(sizeof(char *) * (d->grid_hei + 1))))
		return (NULL);
	i = 0;
	grid[d->grid_hei] = NULL;
	while (i < d->grid_hei)
	{
		if (get_next_line(0, line) != 1)
			return (NULL);
		if (!chk_grid_line_format(d->grid_wid, i, *line))
			return (NULL);
		tmp = ft_strchr(*line, ' ') + 1;
		grid[i] = ft_strdup(tmp);
		ft_strdel(line);
		i += 1;
	}
	return (grid);
}
