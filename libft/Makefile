# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 13:59:02 by tbeauzam          #+#    #+#              #
#    Updated: 2017/03/16 13:52:41 by tbeauzam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
SRC_NAME	=	ft_abs.c \
				ft_atoi.c \
				ft_atol.c \
				ft_strtol.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isupper.c \
				ft_itoa.c \
				ft_alltoa.c \
				ft_ualltoa.c \
				ft_itoa_base.c \
				ft_alltoa_base.c \
				ft_ualltoa_base.c \
				ft_lstadd_front.c \
				ft_lstadd_back.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lst_free.c \
				ft_get_file.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_min.c \
				ft_max.c \
				ft_putchar.c \
				ft_putnchar.c \
				ft_wputchar.c \
				ft_putchar_fd.c \
				ft_putnchar_fd.c \
				ft_wputchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putlongnbr.c \
				ft_putnbr_base.c \
				ft_putlongnbr_base.c \
				ft_putnbr_fd.c \
				ft_putlongnbr_fd.c \
				ft_putnbr_base_fd.c \
				ft_putlongnbr_base_fd.c \
				ft_putstr.c \
				ft_wputstr.c \
				ft_putnstr.c \
				ft_wputnstr.c \
				ft_putstr_fd.c \
				ft_wputstr_fd.c \
				ft_putnstr_fd.c \
				ft_wputnstr_fd.c \
				ft_swap.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_wstrdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_wstrlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_str_remc.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_lower_str.c \
				ft_upper_str.c \
				ft_strndup.c \
				ft_wstrndup.c \
				ft_strcpy_to_c.c \
				get_next_line.c \
				ft_pow.c \
				ft_printf.c \
				ft_printf_get_params.c \
				ft_printf_handle_int.c \
				ft_printf_handle_o.c \
				ft_printf_handle_u.c \
				ft_printf_handle_x.c \
				ft_printf_handle_uppercase_x.c \
				ft_printf_handle_s.c \
				ft_printf_handle_c.c \
				ft_printf_handle_p.c \
				ft_printf_handle_percent.c \
				ft_printf_handle_error.c \
				ft_printf_addendum_a.c \
				ft_printf_addendum_b.c \
				ft_printf_addendum_c.c \
				ft_printf_addendum_d.c \
				ft_printf_addendum_e.c \
				ft_printf_addendum_f.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC_PATH	=	./src
OBJ_PATH	=	./obj
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC			=	-I ./include
INC_FILE	=	./include/libft.h \
				./include/get_next_line.h \
				./include/ft_printf.h

.PHONY: all, clean, fclean, re

all:				$(NAME)

$(NAME):			$(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ_PATH)/%.o:		$(SRC_PATH)/%.c $(INC_FILE)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || :

fclean:				clean
	@rm -f $(NAME)

re:					fclean all
