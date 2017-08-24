/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:23:06 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 16:38:55 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static void		print_winner(t_data *d)
{
	wcolor_set(d->info, 1, NULL);
	if (d->cur == d->head)
		wprintw(d->info, "Beginning...%60s", "");
	else if (d->cur == d->tail && d->p1_score > d->p2_score)
	{
		wcolor_set(d->info, 10, NULL);
		wprintw(d->info, "%s ", d->p1_name);
		wcolor_set(d->info, 1, NULL);
		wprintw(d->info, "won the game!%50s", "");
	}
	else if (d->cur == d->tail && d->p2_score > d->p1_score)
	{
		wcolor_set(d->info, 11, NULL);
		wprintw(d->info, "%s ", d->p2_name);
		wcolor_set(d->info, 1, NULL);
		wprintw(d->info, "won the game!%50s", "");
	}
	else
		wprintw(d->info, "Draw!%60s", "");
}

void			print_some_info(t_data *d)
{
	if (d->cur->id == d->tail->id || d->cur->got == NULL)
		print_winner(d);
	else if (ft_strchr(d->cur->got, 'O'))
	{
		wcolor_set(d->info, 10, NULL);
		if (d->p1_name)
			wprintw(d->info, "%s ", d->p1_name);
		wcolor_set(d->info, 1, NULL);
		if (d->cur->p1_alive)
			wprintw(d->info, "successfully placed a piece.%50s", "");
		else
			wprintw(d->info, "failed to place a piece!%50s", "");
	}
	else if (ft_strchr(d->cur->got, 'X'))
	{
		wcolor_set(d->info, 11, NULL);
		if (d->p2_name)
			wprintw(d->info, "%s ", d->p2_name);
		wcolor_set(d->info, 1, NULL);
		if (d->cur->p2_alive)
			wprintw(d->info, "successfully placed a piece.%50s", "");
		else
			wprintw(d->info, "failed to place a piece!%50s", "");
	}
}

static void		find_death(t_data *d)
{
	d->cur = d->head;
	while (d->cur->next && (d->cur->p1_alive && d->cur->p2_alive))
		d->cur = d->cur->next;
}

int				handle_inputs(t_data *d)
{
	int		ch;

	ch = getch();
	if (ch == 81)
		return (0);
	if (ch == 258 || ch == 338)
		if (d->cur->prev)
			d->cur = d->cur->prev;
	if (ch == 259 || ch == 339)
		if (d->cur->next)
			d->cur = d->cur->next;
	if (ch == 102)
		d->cur = d->head;
	if (ch == 108)
		d->cur = d->tail;
	if (ch == 100)
		find_death(d);
	return (1);
}
