# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 18:23:37 by llawrenc          #+#    #+#              #
#    Updated: 2022/03/09 16:44:20 by llawrenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fractol
SRC		= 	Sources/main.c\
			Sources/support_functions.c\
			Sources/key_hook.c\
			Sources/fractal.c\
			Sources/for_window.c\
			Sources/mouse_hook.c\

HEADER	= 	Includes/fractol.h
OBJ		= 	$(SRC:%.c=%.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)
LIB		=	-L ./Includes -lmlx -framework OpenGL -framework AppKit

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(LIB) $(CFLAGS) $(OBJ) -o $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

re		: fclean all
