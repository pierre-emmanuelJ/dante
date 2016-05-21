##
## Makefile for dante in /home/jacqui_p/rendu/IA/dante/generateur/
##
## Made by Pierre-Emmanuel Jacquier
## Login   <jacqui_p@epitech.eu>
##
## Started on  Thu May 19 16:24:05 2016 Pierre-Emmanuel Jacquier
## Last update Thu May 19 16:24:05 2016 Pierre-Emmanuel Jacquier
##

CC		=	gcc

RM		=	rm -f

SRCDIR	=	./src/

SRC		=	./src/main.c \
				./src/coord.c \
				./src/display.c \
				./src/dead_end.c \
				./src/create_map.c \
				./src/move.c \
				./src/check_move.c \
				./src/string_equal.c \
	  		./src/generator.c

INCDIR	=	./include

OBJ		=	$(SRC:.c=.o)

NAME	=	generateur

CFLAGS	= -I./include -W -O3 -funroll-all-loops -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(SRC) $(CFLAGS)


clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
