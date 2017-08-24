/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:58:57 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/23 13:11:00 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../../libft/include/libft.h"

# define COEFF_FOE	3
# define COEFF_ALLY	2
# define COEFF_VOID	1.5

typedef struct		s_move
{
	struct s_move	*next;
	int				x;
	int				y;
	int				backup_i;
	int				backup_j;
	int				limit_x;
	int				limit_y;
	int				foe_count;
	int				ally_count;
	int				void_count;
	int				border_count;
	int				nearest_foe;
	int				diff_count;
	int				can_place_near;
}					t_move;

typedef struct		s_piece
{
	char			**p;
	int				piece_wid;
	int				piece_hei;
	int				form_x;
	int				form_y;
	int				form_wid;
	int				form_hei;
}					t_piece;

typedef struct		s_data
{
	t_piece			*piece;
	t_move			*moves;
	char			*plateau_line;
	char			**grid;
	double			occupation;
	int				contact;
	int				can_place_near;
	int				nb_turns;
	int				my_total;
	int				my_count_x;
	int				my_count_y;
	int				my_middle_x;
	int				my_middle_y;
	int				foe_total;
	int				foe_count_x;
	int				foe_count_y;
	int				foe_middle_x;
	int				foe_middle_y;
	int				grid_hei;
	int				grid_wid;
	int				x_answer;
	int				y_answer;
	int				last_x;
	int				last_y;
	char			c;
	char			ennemy;
}					t_data;

int					read_grid_and_piece(t_data **data);
int					find_the_best_place(t_data *data);
int					count_contacts(t_data *d, int i, int j, char target);
int					count_borders(t_data *d, int i, int j, int result);
void				coefficialize(t_move *cur);
void				calculate_my_middle(t_data *d, int mode);
int					can_expand(t_data *d, int x, int y);
int					find_nearest_foe(t_data *d, t_move *cur, int i, int j);
void				find_target(t_data *data);
t_move				*play_to_expand(t_data *d);
t_move				*circle_ennemy(t_data *d);

void				get_piece_info(t_piece **piece);
int					waste_next_line(char **line);
int					chk_plateau_line(t_data *d, char *line);
int					chk_gd_line(char *tmp, char **line, size_t x);
int					chk_grid_line_format(int height, char *s);
int					chk_piece_line(t_piece *p, char *s);

#endif
