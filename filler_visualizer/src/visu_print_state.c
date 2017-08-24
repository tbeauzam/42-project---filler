/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:04:41 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/20 19:07:19 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

void			dead_or_alive(t_data *d)
{
	if (d->cur->p1_alive)
	{
		wcolor_set(d->info, 12, NULL);
		mvwprintw(d->info, 2, 17, "%-15s", "alive");
	}
	else
	{
		wcolor_set(d->info, 13, NULL);
		mvwprintw(d->info, 2, 17, "%-15s", "dead");
	}
	if (d->cur->p2_alive)
	{
		wcolor_set(d->info, 12, NULL);
		wprintw(d->info, "%-8s", "alive");
	}
	else
	{
		wcolor_set(d->info, 13, NULL);
		wprintw(d->info, "%-8s", "dead");
	}
}

char			*smooth_names(char *s, int len)
{
	char		tmp[len];
	char		*result;
	int			i;

	ft_bzero(tmp, len);
	if (!(result = ft_strrchr(s, '/') + 1))
		result = s;
	i = 0;
	while (result[i] && result[i] != '.')
	{
		tmp[i] = result[i];
		i += 1;
	}
	result = ft_strdup(tmp);
	return (result);
}

static int		find_sum(t_data *d, int i, int j, char target)
{
	int		sum;

	sum = 0;
	if (i < d->grid_wid - 1 && ft_toupper(d->cur->grid[j][i + 1]) == target)
		sum += 1;
	if (j < d->grid_hei - 1 && ft_toupper(d->cur->grid[j + 1][i]) == target)
		sum += 2;
	if (i > 0 && ft_toupper(d->cur->grid[j][i - 1]) == target)
		sum += 4;
	if (j > 0 && ft_toupper(d->cur->grid[j - 1][i]) == target)
		sum += 8;
	return (sum);
}

static void		check_cell(t_data *d, int i, int j)
{
	if (d->cur->grid[j][i] == 'O')
		wcolor_set(d->game, 3, NULL);
	else if (d->cur->grid[j][i] == 'o')
		wcolor_set(d->game, 4, NULL);
	else if (d->cur->grid[j][i] == 'X')
		wcolor_set(d->game, 5, NULL);
	else if (d->cur->grid[j][i] == 'x')
		wcolor_set(d->game, 6, NULL);
	else if (d->cur->grid[j][i] != '.')
		wcolor_set(d->game, 8, NULL);
	else
		wcolor_set(d->game, 1, NULL);
}

void			print_state(t_data *d, int i, int j)
{
	while (j < d->grid_hei)
	{
		i = 0;
		while (i < d->grid_wid)
		{
			check_cell(d, i, j);
			if (ft_toupper(d->cur->grid[j][i]) == 'O'
					|| ft_toupper(d->cur->grid[j][i]) == 'X')
				print_tile_in_window
(find_sum(d, i, j, ft_toupper(d->cur->grid[j][i])), i, j, d->game);
			else
				mvwprintw(d->game, j + 3, i * 2 + 3, "  ");
			i += 1;
		}
		j += 1;
	}
	wrefresh(d->game);
}
