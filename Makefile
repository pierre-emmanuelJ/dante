##
## Makefile for dante in /home/nico/rendu/S02/IA/dante
## 
## Made by Nicolas Loriot
## Login   <loriot_n@epitech.net>
## 
## Started on  Sat May 21 18:30:51 2016 Nicolas Loriot
## Last update Sat May 21 18:32:48 2016 Nicolas Loriot
##

all:
	(cd largeur; make all)
	(cd profondeur; make all)
	(cd astar; make all)
	(cd genererateur; make all)

re:
	(cd largeur; make all)
	(cd profondeur; make all)
	(cd astar; make all)
	(cd genererateur; make all)

clean:
	(cd largeur; make all)
	(cd profondeur; make all)
	(cd astar; make all)
	(cd genererateur; make all)

fclean:
	(cd largeur; make all)
	(cd profondeur; make all)
	(cd astar; make all)
	(cd genererateur; make all)

.PHONY: all clean fclean re
