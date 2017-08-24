/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:58:45 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 18:27:26 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static void		set_corners(int i, int j)
{
	mvaddch(0, 0, ACS_ULCORNER);
	mvaddch(0, i * 2 + 1, ACS_URCORNER);
	mvaddch(j - 1, 0, ACS_LLCORNER);
	mvaddch(j - 1, i * 2 + 1, ACS_LRCORNER);
}

static void		draw_border(t_data *d, int i, int j)
{
	color_set(8, NULL);
	while (i < d->grid_wid + 1)
	{
		mvaddch(0, i * 2, ACS_HLINE);
		addch(ACS_HLINE);
		mvaddch(d->grid_hei + 1, i * 2, ACS_HLINE);
		addch(ACS_HLINE);
		i += 1;
	}
	while (j <= d->grid_hei + 1)
	{
		mvaddch(j, 0 * 2, ACS_VLINE);
		printw(" ");
		mvprintw(j, i * 2, " ");
		addch(ACS_VLINE);
		if (j == 0 || j == d->grid_hei + 1)
		{
			mvaddch(j, 1, ACS_HLINE);
			mvaddch(j, i * 2, ACS_HLINE);
		}
		j += 1;
	}
	set_corners(i, j);
}

static int		find_sum(t_data *d, int i, int j, char target)
{
	int		sum;

	sum = 0;
	if (i < d->grid_wid - 1 && ft_toupper(d->tail->grid[j][i + 1]) == target)
		sum += 1;
	if (j < d->grid_hei - 1 && ft_toupper(d->tail->grid[j + 1][i]) == target)
		sum += 2;
	if (i > 0 && ft_toupper(d->tail->grid[j][i - 1]) == target)
		sum += 4;
	if (j > 0 && ft_toupper(d->tail->grid[j - 1][i]) == target)
		sum += 8;
	return (sum);
}

static void		draw_last_state(t_data *d, t_state *last, int i, int j)
{
	while (j < d->grid_hei)
	{
		i = 0;
		while (i < d->grid_wid)
		{
			if (last->grid[j][i] == 'O')
				color_set(3, NULL);
			else if (last->grid[j][i] == 'o')
				color_set(4, NULL);
			else if (last->grid[j][i] == 'X')
				color_set(5, NULL);
			else if (last->grid[j][i] == 'x')
				color_set(6, NULL);
			else
				color_set(1, NULL);
			if (ft_toupper(last->grid[j][i]) == 'O'
					|| ft_toupper(last->grid[j][i]) == 'X')
				print_tile
(find_sum(d, i, j, ft_toupper(last->grid[j][i])), i, j);
			else
				mvprintw(j + 1, (i + 1) * 2, "  ");
			i += 1;
		}
		j += 1;
	}
}

int				loading_screen(t_data **data, int i, int j)
{
	t_data		*d;

	d = *data;
	if (!(check_for_term_size_changes(d)))
		return (0);
	if (!d->first_print)
	{
		clear();
		refresh();
		draw_border(d, i, j);
		print_names_previsu(d);
	}
	if (d->tail)
		draw_last_state(d, d->tail, 0, 0);
	refresh();
	return (1);
}
