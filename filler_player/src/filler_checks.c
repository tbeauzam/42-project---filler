/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:44:51 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/20 19:11:03 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				chk_plateau_line(t_data *d, char *line)
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

int				chk_piece_line(t_piece *p, char *s)
{
	int		len;
	char	*tmp;

	if (!ft_strnstr(s, "Piece ", 6))
		return (0);
	tmp = ft_strchr(s, ' ');
	len = ft_strlen(tmp);
	if (tmp[len] || tmp[len - 1] != ':')
		return (0);
	if ((p->piece_hei = ft_strtol(tmp, &tmp, 10)) <= 0)
		return (0);
	if ((p->piece_wid = ft_strtol(tmp, NULL, 10)) <= 0)
		return (0);
	return (1);
}

int				chk_grid_line_format(int height, char *s)
{
	int		i;

	i = 0;
	while (ft_isdigit(s[i]))
		i += 1;
	if (s[i] != ' ')
		return (0);
	if (ft_atol(s) != height)
		return (0);
	return (1);
}

int				chk_gd_line(char *tmp, char **line, size_t x)
{
	char	*s;

	s = *line;
	if (ft_strlen(tmp) > x)
		return (0);
	if (!ft_isdigit(s[0]) || !ft_isdigit(s[1])
			|| !ft_isdigit(s[2]))
		return (0);
	if ((x > 999 && !ft_isdigit(s[3]))
			|| (x > 9999 && !ft_isdigit(s[3]) && !ft_isdigit(s[4])))
		return (0);
	return (1);
}
