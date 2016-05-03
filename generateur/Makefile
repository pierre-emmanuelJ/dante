##
## Makefile for dante in /home/jacqui_p/rendu/IA/dante/
##
## Made by Pierre-Emmanuel Jacquier
## Login   <jacqui_p@epitech.eu>
##
## Started on  Tue May  3 17:43:27 2016 Pierre-Emmanuel Jacquier
## Last update Tue May  3 17:43:27 2016 Pierre-Emmanuel Jacquier
##

CC	= cc

RM	= rm -f

CFLAGS	+= -I. -W -Wall -Wextra

NAME	= generateur

SRCS	= create_map.c \
	  		generator.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
