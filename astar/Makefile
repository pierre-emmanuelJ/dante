##
## Makefile for dante in /home/nico/rendu/S02/IA/dante
## 
## Made by Nicolas Loriot
## Login   <loriot_n@epitech.net>
## 
## Started on  Mon May 02 12:40:32 2016 Nicolas Loriot
## Last update Fri May 20 21:34:30 2016 Nicolas Loriot
##

CC		=	gcc

RM		=	rm -f

SRCDIR	=	./src/

SRC		=	src/resolve.c \
			src/main.c \
			src/fill_tree.c \
			src/get_next_line.c \
			src/queue_op.c \
			src/heuristic.c \

INCDIR	=	./include

OBJ		=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	= -I./include -Wall -Wextra -O3 -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all


