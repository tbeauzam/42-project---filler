/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_windows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 14:11:33 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/20 14:41:57 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static void		draw_hborder(t_data *d, int i)
{
	if (i % 2)
	{
		wcolor_set(d->game, 7, NULL);
		mvwprintw(d->game, 2, i * 2 + 3, "  ");
		mvwprintw(d->game, 1, i * 2 + 3, " ");
		mvwprintw(d->game, 0, i * 2 + 2, "%3d", i);
		mvwprintw(d->game, d->grid_hei + 3, i * 2 + 3, "  ");
	}
	else
	{
		wcolor_set(d->game, 8, NULL);
		mvwprintw(d->game, 2, i * 2 + 3, "  ");
		mvwprintw(d->game, 1, i * 2 + 2, "%3d", i);
		mvwprintw(d->game, d->grid_hei + 3, i * 2 + 3, "  ");
	}
}

static void		draw_game(t_data *d)
{
	int		i;

	i = 0;
	while (i < d->grid_hei)
	{
		if (i % 2)
			wcolor_set(d->game, 7, NULL);
		else
			wcolor_set(d->game, 8, NULL);
		mvwprintw(d->game, i + 3, 0, "%3d", i);
		mvwprintw(d->game, i + 3, d->grid_wid * 2 + 3, "  ");
		i += 1;
	}
	i = 0;
	while (i < d->grid_wid)
	{
		draw_hborder(d, i);
		i += 1;
	}
	wrefresh(d->game);
}

static void		draw_info(t_data *d)
{
	wcolor_set(d->info, 1, NULL);
	mvwprintw(d->info, 1, 2, "Move:");
	mvwprintw(d->info, 2, 1, "%4d / %4d", d->cur->id - 1, d->tail->id - 1);
	mvwprintw(d->info,
3, 2, "%-15s%-15d%-8d", "Scores:", d->cur->p1_score, d->cur->p2_score);
	mvwprintw(d->info, 1, 48, "%-26s", "f: first move");
	wprintw(d->info, "UP, PGUP or mouse scroll UP: move forward");
	mvwprintw(d->info, 2, 48, "%-26s", "d: moment of first death");
	wprintw(d->info, "DOWN, PGDN or mouse scroll DOWN: rewind");
	mvwprintw(d->info, 3, 48, "%-26s", "l: last move");
	wprintw(d->info, "MAJ + q: quit application");
	wcolor_set(d->info, 10, NULL);
	if (d->p1_name)
		mvwprintw(d->info, 1, 17, "%-15.12s", d->p1_name);
	wcolor_set(d->info, 11, NULL);
	if (d->p2_name)
		wprintw(d->info, "%-15.12s", d->p2_name);
	dead_or_alive(d);
	wcolor_set(d->info, 1, NULL);
	mvwprintw(d->info, 5, 2, "> ");
	print_some_info(d);
	wrefresh(d->info);
}

static void		draw_top(t_data *d)
{
	wcolor_set(d->top, 9, NULL);
	mvwprintw(d->top, 1, 0, "                                         __ ");
	mvwprintw(d->top, 2, 0, " _____ _ _ _         _____ _     _   _  |  |");
	mvwprintw(d->top, 3, 0, "|   __|_| | |___ ___|   __|_|___| |_| |_|  |");
	mvwprintw(d->top, 4, 0, "|   __| | | | -_|  _|   __| | . |   |  _|__|");
	mvwprintw(d->top, 5, 0, "|__|  |_|_|_|___|_| |__|  |_|_  |_|_|_| |__|");
	mvwprintw(d->top, 6, 0, "                            |___|           ");
	wcolor_set(d->top, 10, NULL);
	if (d->p1_name)
		mvwprintw(d->top, 8, 12, "%s", d->p1_name);
	else
		mvwprintw(d->top, 8, 14, "No one");
	wcolor_set(d->top, 9, NULL);
	wprintw(d->top, " - VS - ");
	wcolor_set(d->top, 11, NULL);
	if (d->p2_name)
		wprintw(d->top, "%s", d->p2_name);
	else
		wprintw(d->top, "No one");
	wrefresh(d->top);
}

void			draw_windows(t_data *d)
{
	draw_top(d);
	draw_game(d);
	draw_info(d);
	refresh();
}
