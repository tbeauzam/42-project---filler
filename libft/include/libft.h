/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:08:01 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/26 17:18:50 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <inttypes.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *s);
size_t				ft_wstrlen(const wchar_t *s);
char				*ft_strdup(const char *s1);
wchar_t				*ft_wstrdup(const wchar_t *s);
char				*ft_strndup(const char *s1, size_t n);
wchar_t				*ft_wstrndup(const wchar_t *s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *src, const char *dst, size_t len);
size_t				ft_strcpy_to_c(char *dest, char *src, size_t len, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little, size_t l);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long				ft_strtol(const char *str, char **endptr, int base);

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_lower_str(char *s);
char				*ft_upper_str(char *s);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_swap(void *a, void *b);

char				*ft_get_file(char *filename);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strrev(char *s);
char				*ft_str_remc(char *s, char c);
char				*ft_itoa(int value);
char				*ft_alltoa(unsigned long long value);
char				*ft_ualltoa(unsigned long long value);
char				*ft_itoa_base(int value, int base);
char				*ft_alltoa_base(unsigned long long value, int base);
char				*ft_ualltoa_base(unsigned long long value, int base);

long				ft_abs(long nb);
long				ft_pow(int nb, int power);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

int					ft_putchar(char c);
int					ft_putnchar(char c, size_t n);
int					ft_wputchar(wint_t c);
int					ft_putstr(const char *s);
int					ft_wputstr(const wchar_t *s);
int					ft_putnstr(const char *s, size_t n);
int					ft_wputnstr(const wchar_t *s, size_t n);
int					ft_putendl(const char *s);
int					ft_putnbr(int n);
int					ft_putlongnbr(long nb);
int					ft_putnbr_base(int n, int base);
int					ft_putlongnbr_base(long nb, int base);
int					ft_putchar_fd(char c, int fd);
int					ft_putnchar_fd(char c, int fd, size_t n);
int					ft_wputchar_fd(wint_t c, int fd);
int					ft_putstr_fd(const char *s, int fd);
int					ft_wputstr_fd(const wchar_t *s, int fd);
int					ft_putnstr_fd(const char *s, int fd, size_t n);
int					ft_wputnstr_fd(const wchar_t *s, int fd, size_t n);
int					ft_putendl_fd(const char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putlongnbr_fd(long nb, int fd);
int					ft_putnbr_base_fd(int n, int base, int fd);
int					ft_putlongnbr_base_fd(long nb, int base, int fd);

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd_front(t_list **alst, t_list *new_elem);
void				ft_lstadd_back(t_list **alst, t_list *new_elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lst_free(void *data, size_t content_size);

#endif
