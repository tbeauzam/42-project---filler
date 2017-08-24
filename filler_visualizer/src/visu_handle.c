/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:58:45 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 14:42:28 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static void		handle_pairs(void)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, 24);
	init_pair(3, 21, 30);
	init_pair(4, COLOR_BLACK, 21);
	init_pair(5, 22, 31);
	init_pair(6, COLOR_BLACK, 23);
	init_pair(7, 25, 26);
	init_pair(8, 26, 25);
	init_pair(9, 27, COLOR_BLACK);
	init_pair(10, 20, COLOR_BLACK);
	init_pair(11, 22, COLOR_BLACK);
	init_pair(12, 28, COLOR_BLACK);
	init_pair(13, 29, COLOR_BLACK);
}

static void		handle_colors(void)
{
	start_color();
	init_color(20, 900, 300, 0);
	init_color(21, 1000, 350, 50);
	init_color(22, 200, 400, 1000);
	init_color(23, 200, 550, 1000);
	init_color(24, 0, 0, 800);
	init_color(25, 100, 100, 100);
	init_color(26, 900, 900, 900);
	init_color(27, 1000, 200, 200);
	init_color(28, 0, 1000, 0);
	init_color(29, 1000, 0, 0);
	init_color(30, 100, 20, 0);
	init_color(31, 0, 20, 100);
	handle_pairs();
}

int				handle_visu(void)
{
	setlocale(LC_ALL, "");
	initscr();
	handle_colors();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	color_set(1, NULL);
	mvprintw(LINES / 3 - 1, COLS / 3, "One moment please...");
	refresh();
	return (1);
}

int				handle_gui(t_data *d)
{
	clear();
	refresh();
	d->top = newwin(10, 44, 0, COLS / 2 - 22);
	d->game = newwin(d->grid_hei + 4, d->grid_wid * 2 + 5,
10, COLS / 2 - (d->grid_wid * 2 + 5) / 2);
	d->info = newwin(20, 120, d->grid_hei + 4 + 10, COLS / 2 - 60);
	d->cur = d->tail;
	freopen("/dev/tty", "rw", stdin);
	while (1)
	{
		if (!(check_for_term_size_changes(d)))
			return (0);
		draw_windows(d);
		print_state(d, 0, 0);
		if (!(handle_inputs(d)))
			break ;
	}
	endwin();
	return (1);
}
