/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visualizer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:23:55 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:33 by chkropok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUALIZER_H
# define FILLER_VISUALIZER_H

# include "../../libft/include/libft.h"
# include <curses.h>
# include <locale.h>

typedef struct			s_piece
{
	char				**p;
	int					piece_wid;
	int					piece_hei;
	int					form_x;
	int					form_y;
	int					form_wid;
	int					form_hei;
}						t_piece;

typedef struct			s_state
{
	char				**grid;
	char				*got;
	t_piece				*piece;
	struct s_state		*next;
	struct s_state		*prev;
	int					id;
	int					p1_alive;
	int					p2_alive;
	int					p1_score;
	int					p2_score;
}						t_state;

typedef struct			s_data
{
	WINDOW				*top;
	WINDOW				*game;
	WINDOW				*info;
	t_state				*head;
	t_state				*tail;
	t_state				*cur;
	char				*p1_name;
	char				*p2_name;
	char				*got;
	char				*plateau_line;
	int					grid_wid;
	int					grid_hei;
	int					nb_players;
	int					p1_alive;
	int					p2_alive;
	int					p1_score;
	int					p2_score;
	int					term_hei;
	int					term_wid;
	int					first_print;
}						t_data;

int						chk_plateau_line(t_data *d, char *line);
int						chk_piece_line(char *s);
int						chk_grid_line_format(int width, int height, char *s);
int						get_current_state(t_data **data, char **line);
int						handle_death(t_data **data, char **line);
int						check_header(char **line, int i);
int						print_error(t_data *d, int code);
char					**read_grid(t_data *d, char **line);
t_piece					*read_piece(char **line, int i);
t_state					*create_state(t_data *d);
void					waste_next_line(char **line);
void					print_some_info(t_data *d);

int						handle_visu(void);
int						handle_gui(t_data *data);
int						handle_inputs(t_data *d);
int						loading_screen(t_data **d, int i, int j);
int						check_for_term_size_changes(t_data *d);
int						check_for_avalaible_space(t_data *d);
void					print_names_previsu(t_data *d);
char					*smooth_names(char *input, int len);
void					print_tile(int sum, int i, int j);
void					print_tile_in_window(int sum, int i, int j, WINDOW *w);
void					dead_or_alive(t_data *d);
void					draw_windows(t_data *d);
void					print_state(t_data *d, int i, int j);

#endif
