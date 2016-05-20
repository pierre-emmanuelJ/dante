/*
** main.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/src/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu May 19 16:50:33 2016 Pierre-Emmanuel Jacquier
** Last update Thu May 19 16:50:33 2016 Pierre-Emmanuel Jacquier
*/

#include <unistd.h>
#include <stdlib.h>
#include "generator.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void	x_y(t_x_y *coord, char **argv)
{
  coord->x = atoi(argv[1]);
  coord->y = atoi(argv[2]);
  coord->width = coord->x;
  coord->height = coord->y;
  if (coord->x % 2 == 0)
    coord->x -= 1;
  if (coord->y % 2 == 0)
    coord->y -= 1;
}

int	main(int argc, char **argv)
{
  srand(time(NULL));
  if ((argc > 1 && argc == 4))
    {
      if (string_equals(argv[3], "parfait"))
	perfect(argv, 0, 0);
      if (string_equals(argv[3], "--live"))
	perfect(argv, 1, 1);
    }
  else if ((argc > 1 && argc == 3))
    perfect(argv, 0, 1);
  else if ((argc > 1 && argc == 5))
    {
      if (string_equals(argv[3], "parfait")
	  && string_equals(argv[4], "--live"))
	perfect(argv, 1, 0);
    }
  else
    write(1, "./generateur x y [parfait]\n", 27);
  return (0);
}
