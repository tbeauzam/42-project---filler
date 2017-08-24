/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:58:03 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/18 11:59:55 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			print_error(void)
{
	ft_putendl_fd("error: bad input", 2);
	return (1);
}

static void			clear_moves(t_move **moves)
{
	t_move		*m;
	t_move		*tmp;

	m = *moves;
	while (m)
	{
		tmp = m;
		m = m->next;
		free(tmp);
		tmp = NULL;
	}
}

static void			init_the_rest(t_data **d)
{
	(*d)->can_place_near = 0;
	(*d)->occupation = 0;
	(*d)->nb_turns = 0;
	(*d)->my_total = 0;
	(*d)->my_count_x = 0;
	(*d)->my_count_y = 0;
	(*d)->my_middle_x = 0;
	(*d)->my_middle_y = 0;
	(*d)->foe_total = 0;
	(*d)->foe_count_x = 0;
	(*d)->foe_count_y = 0;
	(*d)->foe_middle_x = 0;
	(*d)->foe_middle_y = 0;
	(*d)->contact = 0;
	(*d)->last_x = 0;
	(*d)->last_y = 0;
}

static t_data		*create_data(char **line)
{
	t_data		*new;
	char		*temp;

	new = NULL;
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (!(temp = ft_strchr(*line, 'p')) || !ft_strnstr(*line, "$$$ exec p", 10))
		return (NULL);
	if (!temp[1] || !temp[2] || (temp[1] != '1' && temp[1] != '2')
			|| !ft_strstr(temp, " : ["))
		return (NULL);
	new->c = (temp[1] == '1' ? 'O' : 'X');
	new->ennemy = (temp[1] == '2' ? 'O' : 'X');
	new->grid_hei = 0;
	new->grid_wid = 0;
	new->x_answer = 0;
	new->y_answer = 0;
	new->plateau_line = NULL;
	new->grid = NULL;
	new->moves = NULL;
	init_the_rest(&new);
	ft_strdel(line);
	return (new);
}

int					main(void)
{
	char		*line;
	t_data		*data;

	line = NULL;
	if (get_next_line(0, &line) != 1)
		return (1);
	if (!(data = create_data(&line)))
		return (print_error());
	while (1)
	{
		if (data->moves)
			clear_moves(&(data->moves));
		if (!(read_grid_and_piece(&data)))
			return (print_error());
		if (!find_the_best_place(data))
			break ;
		if (line)
			ft_strdel(&line);
		ft_printf("%d %d\n", data->y_answer, data->x_answer);
	}
	ft_putstr("0 0\n");
	return (0);
}
