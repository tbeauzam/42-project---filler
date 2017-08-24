/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_char_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 01:57:54 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/20 18:22:20 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

static void		next_check_c(int sum, int i, int j)
{
	if (sum == 15)
		mvprintw(j + 1, (i + 1) * 2, "  ");
	else if (sum == 0)
		mvprintw(j + 1, (i + 1) * 2, "[]");
}

static void		next_check_b(int sum, int i, int j)
{
	if (sum > 14 || sum == 0)
		next_check_c(sum, i, j);
	else if (sum == 10)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_VLINE);
		addch(ACS_VLINE);
	}
	else if (sum == 11)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_VLINE);
		printw(" ");
	}
	else if (sum == 12)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_HLINE);
		addch(ACS_LRCORNER);
	}
	else if (sum == 14)
	{
		mvprintw(j + 1, (i + 1) * 2, " ");
		addch(ACS_VLINE);
	}
}

static void		next_check_a(int sum, int i, int j)
{
	if ((sum > 9 && sum != 13) || sum == 0)
		next_check_b(sum, i, j);
	else if (sum == 5 || sum == 7 || sum == 13)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_HLINE);
		addch(ACS_HLINE);
	}
	else if (sum == 6)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_HLINE);
		addch(ACS_URCORNER);
	}
	else if (sum == 8)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_LLCORNER);
		addch(ACS_LRCORNER);
	}
	else if (sum == 9)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_LLCORNER);
		addch(ACS_HLINE);
	}
}

void			print_tile(int sum, int i, int j)
{
	if (sum > 4 || sum == 0)
		next_check_a(sum, i, j);
	else if (sum == 1)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_DIAMOND);
		addch(ACS_HLINE);
	}
	else if (sum == 2)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_ULCORNER);
		addch(ACS_URCORNER);
	}
	else if (sum == 3)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_ULCORNER);
		addch(ACS_HLINE);
	}
	else if (sum == 4)
	{
		mvaddch(j + 1, (i + 1) * 2, ACS_HLINE);
		addch(ACS_DIAMOND);
	}
}
