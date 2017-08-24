/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:44:51 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 19:09:14 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualizer.h"

void				waste_next_line(char **line)
{
	get_next_line(0, line);
	if (*line)
		ft_strdel(line);
}

int					chk_plateau_line(t_data *d, char *line)
{
	char	*tmp;
	int		len;

	if (!d->plateau_line)
	{
		tmp = line;
		if (!ft_strnstr(line, "Plateau ", 8))
			return (0);
		tmp = ft_strchr(line, ' ');
		len = ft_strlen(tmp);
		if (tmp[len] || tmp[len - 1] != ':')
			return (0);
		d->plateau_line = ft_strdup(line);
	}
	else if (!ft_strequ(line, d->plateau_line))
		return (0);
	return (1);
}

int					chk_piece_line(char *s)
{
	int		len;
	char	*tmp;

	if (!ft_strnstr(s, "Piece ", 6))
		return (0);
	tmp = ft_strchr(s, ' ');
	len = ft_strlen(tmp);
	if (tmp[len] || tmp[len - 1] != ':')
		return (0);
	if (ft_strtol(tmp, &tmp, 10) <= 0)
		return (0);
	if (ft_strtol(tmp, NULL, 10) <= 0)
		return (0);
	return (1);
}

int					chk_grid_line_format(int width, int height, char *s)
{
	int		i;

	i = 0;
	while (ft_isdigit(s[i]))
		i += 1;
	if (s[i] != ' ')
		return (0);
	if (ft_strtol(s, NULL, 10) != height)
		return (0);
	if (!(s = ft_strchr(s, ' ') + 1))
		return (0);
	if ((int)ft_strlen(s) > width)
		return (0);
	return (1);
}
