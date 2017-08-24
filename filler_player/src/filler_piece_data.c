/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_addendum_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkropok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:11:14 by chkropok          #+#    #+#             */
/*   Updated: 2017/03/16 15:48:42 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_form_hei(t_piece **piece)
{
	t_piece		*p;
	int			i;
	int			j;

	p = *piece;
	i = p->piece_hei - 1;
	while (i >= 0)
	{
		j = p->piece_wid - 1;
		while (j >= 0)
		{
			if (p->p[i][j] == '*')
				break ;
			j -= 1;
		}
		if (j >= 0)
			break ;
		i -= 1;
	}
	p->form_hei = i - p->form_y + 1;
}

static void		get_form_wid(t_piece **piece)
{
	t_piece		*p;
	int			i;
	int			j;

	p = *piece;
	i = p->piece_wid - 1;
	while (i >= 0)
	{
		j = 0;
		while (p->p[j])
		{
			if (p->p[j][i] == '*')
				break ;
			j += 1;
		}
		if (j != p->piece_hei)
			break ;
		i -= 1;
	}
	p->form_wid = i - p->form_x + 1;
}

static void		get_form_x(t_piece **piece)
{
	t_piece		*p;
	int			i;
	int			j;

	p = *piece;
	i = 0;
	while (i < p->piece_wid)
	{
		j = 0;
		while (j < p->piece_hei)
		{
			if (p->p[j][i] == '*')
				break ;
			j += 1;
		}
		if (j != p->piece_hei)
			break ;
		i += 1;
	}
	p->form_x = i;
}

void			get_piece_info(t_piece **piece)
{
	t_piece		*p;
	int			i;
	int			j;

	p = *piece;
	i = 0;
	while (p->p[i])
	{
		j = 0;
		while (p->p[i][j])
		{
			if (p->p[i][j] == '*')
				break ;
			j += 1;
		}
		if (j != p->piece_wid)
			break ;
		i += 1;
	}
	p->form_y = i;
	get_form_x(piece);
	get_form_wid(piece);
	get_form_hei(piece);
}

int				waste_next_line(char **line)
{
	*line = NULL;
	if (get_next_line(0, line) != 1)
		return (0);
	ft_strdel(line);
	return (1);
}
