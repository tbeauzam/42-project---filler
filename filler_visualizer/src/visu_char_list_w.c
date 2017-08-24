/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_char_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 01:57:54 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/20 18:50:47 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static void		next_check_c(int sum, int i, int j, WINDOW *cur)
{
	if (sum == 15)
		mvwprintw(cur, j + 3, i * 2 + 3, "  ");
	else if (sum == 0)
		mvwprintw(cur, j + 3, i * 2 + 3, "[]");
}

static void		next_check_b(int sum, int i, int j, WINDOW *cur)
{
	if (sum > 14 || sum == 0)
		next_check_c(sum, i, j, cur);
	else if (sum == 10)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_VLINE);
		waddch(cur, ACS_VLINE);
	}
	else if (sum == 11)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_VLINE);
		wprintw(cur, " ");
	}
	else if (sum == 12)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_HLINE);
		waddch(cur, ACS_LRCORNER);
	}
	else if (sum == 14)
	{
		mvwprintw(cur, j + 3, i * 2 + 3, " ");
		waddch(cur, ACS_VLINE);
	}
}

static void		next_check_a(int sum, int i, int j, WINDOW *cur)
{
	if ((sum > 9 && sum != 13) || sum == 0)
		next_check_b(sum, i, j, cur);
	else if (sum == 5 || sum == 7 || sum == 13)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_HLINE);
		waddch(cur, ACS_HLINE);
	}
	else if (sum == 6)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_HLINE);
		waddch(cur, ACS_URCORNER);
	}
	else if (sum == 8)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_LLCORNER);
		waddch(cur, ACS_LRCORNER);
	}
	else if (sum == 9)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_LLCORNER);
		waddch(cur, ACS_HLINE);
	}
}

void			print_tile_in_window(int sum, int i, int j, WINDOW *cur)
{
	if (sum > 4 || sum == 0)
		next_check_a(sum, i, j, cur);
	else if (sum == 1)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_DIAMOND);
		waddch(cur, ACS_HLINE);
	}
	else if (sum == 2)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_ULCORNER);
		waddch(cur, ACS_URCORNER);
	}
	else if (sum == 3)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_ULCORNER);
		waddch(cur, ACS_HLINE);
	}
	else if (sum == 4)
	{
		mvwaddch(cur, j + 3, i * 2 + 3, ACS_HLINE);
		waddch(cur, ACS_DIAMOND);
	}
}
