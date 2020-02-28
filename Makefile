# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/27 18:49:19 by nsalle       #+#   ##    ##    #+#        #
#    Updated: 2020/01/30 00:53:07 by nsalle      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= 	lem-in

CC 		= 	gcc
CFLAGS 	+= 	-Wextra -Werror -Wall -g -flto -O3 -march=native -flto -ffast-math 

SRC 	= 	srcs/choose_path.c				\
			srcs/gestion_tab_ant.c			\
			srcs/combinaison_path.c			\
			srcs/solver.c					\
			srcs/main.c		  				\
			srcs/lem_parsing.c 				\
			srcs/testing.c     				\
			srcs/error.c 	  				\
			srcs/more_error.c				\
			srcs/parsing_tools.c			\
			srcs/lem_parse_rooms.c 			\
			srcs/rmv_path.c					\
			srcs/store_all_paths.c			\
			srcs/path_tools.c				\
			srcs/translate_answ.c			\
			srcs/remove_longest.c			\
			srcs/utils.c					\
			srcs/utils2.c					\
			srcs/free.c						\
			srcs/visu/lem_parse_coords.c 	\
			srcs/visu/check_coords.c		\
			srcs/visu/visu_lemin.c			\
			srcs/visu/print.c				\
			srcs/visu/free_vs.c				\
			srcs/visu/init_items.c			\
			srcs/visu/bresenham.c			\
			srcs/visu/settings.c			\
			srcs/visu/ant_movement.c		\
			srcs/visu/parse_answer.c		\

OBJ		=	$(SRC:.c=.o)

INC		=	-I./$(LFTDIR) -I.

LFTDIR	=	libft_nsalle
LFT		=	-L $(LFTDIR) -lft

RM		=	/bin/rm

all: LFTC $(NAME)

LFTC:
	@$(MAKE) -C $(LFTDIR)

$(NAME): $(OBJ) includes/lemin.h $(LFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(INC) $(LFT) -L ~/.brew/lib -lSDL2 -lSDL2_ttf -lSDL2_image $(OBJ) -o $(NAME)
	@printf "\n|-> \033[32m$(NAME) compiled\033[0m\n\n"

clean:
	@$(MAKE) -C $(LFTDIR) $@
	@$(RM) -rf $(OBJ)
	@printf "|-> \033[31mobjects removed\033[0m\n"

fclean: clean
	@$(MAKE) -C $(LFTDIR) $@
	@$(RM) -f $(NAME)
	@printf "|-> \033[31m$(NAME) deleted\033[0m\n"

re: fclean all

.SILENT: $(OBJ)
.PHONY: all clean fclean re
