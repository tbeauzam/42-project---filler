# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 13:59:02 by tbeauzam          #+#    #+#              #
#    Updated: 2017/03/20 18:24:39 by tbeauzam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	visualizer
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
SRC_NAME	=	main_visu.c \
				visu_addendum_a.c \
				visu_get_current_state.c \
				visu_state_after_death.c \
				visu_loading_screen.c \
				visu_draw_windows.c \
				visu_print_state.c \
				visu_char_list.c \
				visu_char_list_w.c \
				visu_checks.c \
				visu_read.c \
				visu_handle.c \
				visu_inputs.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC_PATH	=	./src
OBJ_PATH	=	./obj
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC			=	-I ./include -I ../libft/include
INC_FILE	=	./include/filler_visualizer.h
LFT			=	-L ../libft -lft -lcurses

.PHONY: all, debug, make_lft, clean, fclean, lft_clean, lft_fclean, re

all:				make_lft ../$(NAME)

../$(NAME):			$(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFT)
	@mv $(NAME) ..
	@echo "Visualizer executable Done!"

$(OBJ_PATH)/%.o:		$(SRC_PATH)/%.c $(INC_FILE)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:				lft_clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || :

fclean:				lft_fclean clean
	@rm -f ../$(NAME)


make_lft:
	@$(MAKE) -C ../libft 1> /dev/null

lft_clean:
	@$(MAKE) -C ../libft clean

lft_fclean:
	@$(MAKE) -C ../libft fclean


re:					fclean all
