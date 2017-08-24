/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:38:07 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/12 15:33:22 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

# define NB_CONV 6
# define CONV_LIST "sSpdDioOuUxXcC%"
# define FLAG_LIST "0123456789#*-+ .hljz"
# define FLAGS "#0-+ "

typedef struct	s_list2
{
	void			*content;
	size_t			content_size;
	struct s_list2	*next;
}				t_list2;

typedef struct	s_params
{
	char			*flags;
	char			*width;
	char			*prec;
	char			*size;
	struct s_params	*next;
}				t_params;

typedef int		(*t_handle_conv)(t_params *, va_list, char);

typedef struct	s_conv_tab
{
	char			*c;
	t_handle_conv	f;
}				t_conv_tab;

int				ft_printf(const char *format, ...);
t_list2			*create_lstd(const void *content, size_t content_size);
void			lstdadd_back(t_list2 **alst, t_list2 *new_elem);
int				check_flag(char c);
t_conv_tab		**create_conv_tab(void);
t_params		*get_params(char *s, char c, int ret, int i);
int				check_wildcard(t_params **params, va_list ap);
int				get_conversions(t_list2 **lst, char *s, int i);
t_params		*create_params_list(t_params **head, t_list2 *conv_list);
int				inc_char_len(wint_t c);
int				wchar_len(wchar_t *s, int *len, char *prec);
char			*handle_that_delicate_case(char **s);
void			change_paddings_in_d(int *p_padd, int *w_padd);
void			check_prec_o(t_params *p, char *s, int len, int *prec_padding);
void			check_prec_d(t_params *p, char *s, int *len, int *p_padd);
void			print_that_thing(char *s, int p_padd, int w_padd);
void			check_width_o(t_params *p, int len, int *w_padd, int p_padd);
void			check_width_x(t_params *p, int len, int *p_padd, int *w_padd);
void			check_width_d(t_params *p, char *s, int *p_padd, int *w_padd);
void			check_width_u(t_params *p, int len, int *w_padd, int p_padd);
void			check_wp_p(t_params *p, int *len, int *p_padd, int *w_padd);
int				special_d_print(t_params *p, int w_padd);
void			savage_incrementation(int *i, int len);
void			clean_things_up(t_list2 **conv_chain, t_params **params_chain);
void			dismantle_tab(t_conv_tab **tab);

int				handle_s(t_params *params, va_list ap, char conv);
int				handle_c(t_params *parans, va_list ap, char conv);
int				handle_p(t_params *parans, va_list ap, char conv);
int				handle_int(t_params *params, va_list ap, char conv);
int				handle_o(t_params *params, va_list ap, char conv, char *arg);
int				handle_u(t_params *params, va_list ap, char conv, char *arg);
int				handle_x(t_params *params, va_list ap, char conv, char *arg);
int				handle_uppercase_x(t_params *params, char *arg);
int				handle_percent(t_params *params, va_list ap, char conv);
int				handle_error(t_params *params, va_list ap, char conv);

#endif
