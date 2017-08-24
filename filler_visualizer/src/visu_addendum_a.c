/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_addendum_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:52:26 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/20 14:12:19 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

int			check_for_avalaible_space(t_data *d)
{
	if (LINES < d->grid_hei + 21 || COLS < 120 || COLS < d->grid_wid * 2 + 6)
		return (0);
	return (1);
}

int			check_for_term_size_changes(t_data *d)
{
	if (d->term_hei == 0 && d->term_wid == 0)
	{
		d->term_hei = LINES;
		d->term_wid = COLS;
		return (1);
	}
	if (d->term_hei != LINES || d->term_wid != COLS)
		return (0);
	return (1);
}

void		print_names_previsu(t_data *d)
{
	color_set(10, NULL);
	if (d->p1_name)
		mvprintw(d->grid_hei + 3, 1, "%s ", d->p1_name);
	else
		mvprintw(d->grid_hei + 3, 1, "No one ");
	color_set(1, NULL);
	printw(" VS ");
	color_set(11, NULL);
	if (d->p2_name)
		printw(" %s", d->p2_name);
	else
		printw(" No one");
	d->first_print = 1;
}
