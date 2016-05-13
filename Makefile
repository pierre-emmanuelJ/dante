##
## Makefile for dante in /home/nico/rendu/S02/IA/dante
## 
## Made by Nicolas Loriot
## Login   <loriot_n@epitech.net>
## 
## Started on  Mon May 02 12:40:32 2016 Nicolas Loriot
## Last update Thu May 12 14:38:27 2016 Nicolas Loriot
##

CC		=	gcc

RM		=	rm -f

SRCDIR	=	./src/

SRC		=	src/resolve.c \
			src/main.c \
			src/fill_tree.c \
			src/visit_maze.c \
			src/get_next_line.c \

INCDIR	=	./include

OBJ		=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	= -I./include -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all


