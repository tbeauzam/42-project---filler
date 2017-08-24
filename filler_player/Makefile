# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 14:53:58 by tbeauzam          #+#    #+#              #
#    Updated: 2017/03/16 13:52:12 by tbeauzam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	tbeauzam.filler
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
SRC_NAME	=	main_filler.c \
				filler_addendum_a.c \
				filler_addendum_b.c \
				filler_read.c \
				filler_checks.c \
				filler_piece_data.c \
				filler_grid_parsing.c \
				filler_find_target.c \
				filler_circling.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC_PATH	=	./src
OBJ_PATH	=	./obj
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC			=	-I ./include -I ../libft/include
INC_FILE	=	./include/filler.h
LFT			=	-L ../libft -lft

.PHONY: all, debug, make_lft, clean, fclean, lft_clean, lft_fclean, re

all:				make_lft ../$(NAME)

../$(NAME):			$(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFT)
	@mv $(NAME) ..
	@echo "Player executable Done!"

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
