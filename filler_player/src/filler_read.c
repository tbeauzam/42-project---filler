/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:02:10 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/16 15:49:26 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_piece	*get_piece(char **line, int i, t_piece *p)
{
	char		*tmp;

	get_next_line(0, line);
	tmp = *line;
	if (!(p = (t_piece *)malloc(sizeof(t_piece))) || !chk_piece_line(p, tmp))
		return (NULL);
	tmp = ft_strchr(tmp, ' ');
	p->piece_hei = ft_strtol(tmp, &tmp, 10);
	p->piece_wid = ft_strtol(tmp, NULL, 10);
	if (!(p->p = (char **)malloc(sizeof(char *) * (p->piece_hei + 1))))
		return (NULL);
	ft_strdel(line);
	while (i < p->piece_hei)
	{
		if (get_next_line(0, line) != 1
				|| ft_strlen(*line) != (size_t)p->piece_wid)
			return (NULL);
		tmp = *line;
		p->p[i] = ft_strdup(tmp);
		ft_strdel(line);
		i += 1;
	}
	p->p[i] = NULL;
	return (p);
}

static int		refresh_grid(t_data **data, char **line, int y, size_t x)
{
	t_data		*d;
	char		*tmp;
	size_t		i;
	int			j;

	d = *data;
	j = 0;
	while (j < y)
	{
		i = 0;
		if (get_next_line(0, line) != 1 || !chk_grid_line_format(j, *line))
			return (0);
		if (!(tmp = ft_strchr(*line, ' ') + 1) || !(chk_gd_line(tmp, line, x)))
			return (0);
		while (i < x)
		{
			if (d->grid[j][i] != tmp[i])
				d->grid[j][i] = tmp[i];
			i += 1;
		}
		ft_strdel(line);
		j += 1;
	}
	return (1);
}

static char		**generate_grid(int y, int x)
{
	char		**tab;
	int			i;

	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * (y + 1))))
		return (NULL);
	i = 0;
	while (i < y)
	{
		tab[i] = NULL;
		if (!(tab[i] = (char *)malloc(x + 1)))
			return (NULL);
		ft_memset(tab[i], '.', x);
		tab[i][x] = '\0';
		i += 1;
	}
	tab[i] = NULL;
	return (tab);
}

static void		free_piece(t_data **data)
{
	t_data		*tmp;
	int			i;

	tmp = *data;
	i = 0;
	while (i < tmp->piece->piece_hei)
	{
		ft_strdel(&(tmp->piece->p[i]));
		i += 1;
	}
	free(tmp->piece->p[i]);
	free(tmp->piece->p);
	free(tmp->piece);
	tmp->piece = NULL;
}

int				read_grid_and_piece(t_data **data)
{
	t_data		*d;
	char		*line;
	char		*temp;

	d = *data;
	line = NULL;
	if (get_next_line(0, &line) != 1)
		return (0);
	if (!chk_plateau_line(d, line) || !(temp = ft_strchr(line, 'u') + 1))
		return (0);
	d->grid_hei = ft_strtol(temp, &temp, 10);
	d->grid_wid = ft_strtol(temp, NULL, 10);
	ft_strdel(&line);
	waste_next_line(&line);
	if (!(d->grid))
		if (!(d->grid = generate_grid(d->grid_hei, d->grid_wid)))
			return (0);
	if (!(refresh_grid(data, &line, d->grid_hei, d->grid_wid)))
		return (0);
	if (d->piece)
		free_piece(data);
	if (!(d->piece = get_piece(&line, 0, NULL)))
		return (0);
	get_piece_info(&(d->piece));
	return (1);
}
