# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 13:59:02 by tbeauzam          #+#    #+#              #
#    Updated: 2017/03/16 12:00:37 by tbeauzam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:				player visu

player:
	@$(MAKE) -C ./filler_player all

visu:
	@$(MAKE) -C ./filler_visualizer all


clean:				player_clean visu_clean

player_clean:
	@$(MAKE) -C ./filler_player clean
	@echo "Objects of player Cleaned!"

visu_clean:
	@$(MAKE) -C ./filler_visualizer clean
	@echo "Objects of visualizer Cleaned!"


fclean:				player_fclean visu_fclean
	@echo "Everything have been exterminated, Sir!"

player_fclean:		player_clean
	@$(MAKE) -C ./filler_player fclean
	@echo "Player executable Cleaned!"

visu_fclean:		visu_clean
	@$(MAKE) -C ./filler_visualizer fclean
	@echo "Visualizer executable Cleaned!"


re:					fclean all
