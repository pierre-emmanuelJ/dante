##
## Makefile for dante in /home/nico/rendu/S02/IA/dante
## 
## Made by Nicolas Loriot
## Login   <loriot_n@epitech.net>
## 
## Started on  Sat May 21 18:30:51 2016 Nicolas Loriot
## Last update Sat May 21 18:37:05 2016 Nicolas Loriot
##

all:
	(cd largeur; make all)
	(cd profondeur; make all)
	(cd astar; make all)
	(cd generateur; make all)

re:
	(cd largeur; make re)
	(cd profondeur; make re)
	(cd astar; make re)
	(cd generateur; make re)

clean:
	(cd largeur; make clean)
	(cd profondeur; make clean)
	(cd astar; make clean)
	(cd generateur; make clean)

fclean:
	(cd largeur; make fclean)
	(cd profondeur; make fclean)
	(cd astar; make fclean)
	(cd generateur; make fclean)

.PHONY: all clean fclean re
