#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/16 10:52:14 by sebgoret          #+#    #+#              #
#    Updated: 2014/01/19 20:16:40 by sebgoret         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all libft clean fclean re

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror -pedantic -std=c89

CC = clang $(CFLAGS)

LIBFT = -L$(DLIB) -lft

LIBX = -L /usr/X11/lib -lmlx -lXext -lX11

DLIB = libft/
DINC = includes/
DSRC = srcs/
DOBJ = objs/
DMAI = ./

SRC =	ft_key_hook.c			\
		ft_mouse_hook.c			\
		ft_expose_hook.c		\
		ft_put_pix_in_img.c		\
		ft_draw_background.c	\
		ft_draw_square.c		\
		ft_draw_circle.c		\
		ft_draw_wall.c			\
		ft_get_map.c			\
		ft_move.c				\
		ft_get_color.c			\
		main.c					\

OBJ = $(patsubst %.c, $(DOBJ)%.o, $(SRC))

RMF = /bin/rm -f
RMD = /bin/rm -Rf
MKD = /bin/mkdir -p

all: libft $(NAME)

$(DOBJ)%.o: $(DMAI)%.c
	@echo "Compilation du main:\033[0;32m"
	@$(MKD) $(DOBJ)
	$(CC) -o $@ -c $< -I $(DINC) -I $(DLIB)$(DINC)
	@echo "\033[0;m\c"

$(DOBJ)%.o: $(DSRC)%.c
	@$(MKD) $(DOBJ)
	@echo "Compilation de l'objet:\033[0;32m"
	$(CC) -o $@ -c $< -I $(DINC) -I $(DLIB)$(DINC)
	@echo "\033[0;m\c"

$(NAME): $(DLIB)libft.a $(OBJ)
	@echo "Creation de l'executable:\033[0;32m"
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(LIBX)
	@echo "\033[0;m\c"

libft:
	@echo "Compilation des objets de la lib:"
	@make -C $(DLIB)

libclean:
	@echo "Suppression des objets de la librairie libft.a:"
	@make -C $(DLIB) clean

libfclean:
	@echo "Suppression de la librairie libft.a:"
	@make -C $(DLIB) fclean

clean:
	@echo "Suppression des objets du projet:\033[0;31m"
	$(RMF) $(OBJ)
	@echo "\033[0;m\c"
	@$(RMD) $(DOBJ)

fclean: clean
	@echo "Suppression de l'executable\033[0;31m"
	$(RMF) $(NAME)
	@echo "\033[0;m\c"

re: fclean all
