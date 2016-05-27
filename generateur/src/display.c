/*
** display.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/src/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu May 19 17:05:19 2016 Pierre-Emmanuel Jacquier
** Last update Thu May 19 17:05:19 2016 Pierre-Emmanuel Jacquier
*/

#include "generator.h"
#include "generator.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void	y_one_of_two(int live, short int *two)
{
  if (*two == 0)
    {
      if (live)
	printf("\x1B[44m*\x1B[0m");
      else
	putchar('*');
      *two += 1;
    }
  else if (*two == 1)
    {
     if (live)
	printf("\x1B[37mX\x1B[0m");
      else
	putchar('X');
      *two = 0;
    }
}

void	x_one_of_two(short int live, int width, int flag)
{
  int	i;

  i = 1;
  putchar('\n');
  if (flag)
    putchar('X');
  while (i < width)
    {
      if (live)
      printf("\x1B[37mX\x1B[0m");
      else
      putchar('X');
      i++;
      if (live)
      printf("\x1B[44m*\x1B[0m");
      else
      putchar('*');
      i++;
    }
}

void	print_char(t_map *map, int i, int live)
{
  if (live)
    {
      if (map[i].index == 0)
	putchar('X');
      else if (map[i].index == 1)
	printf("\x1B[44m*\x1B[0m");
      else if (map[i].index == 6)
	printf("\x1B[41m*\x1B[0m");
    }
  else
    {
      if (map[i].index == 0)
	putchar('X');
      else if (map[i].index == 1)
	putchar('*');
    }
}

void	display_map(t_map *map, short int y, short int live, t_x_y direct)
{
  int	i;
  int	j;
  int	line;
  short int	two;

  two = 0;
  i = 0;
  j = 0;
  line = 0;
  while (line < direct.y)
    {
      while (j < direct.x)
	{
	  print_char(map, i, live);
	  j++;
	  i++;
	}
      if (y)
	y_one_of_two(live, &two);
      if (line < direct.y - 1)
	putchar('\n');
      j = 0;
      line++;
    }
}

void	display_live(t_map *map, int coord, t_x_y direct)
{
  map[coord].index = 6;
  display_map(map, 0, 1, direct);
  printf("\n\n\n");
  map[coord].index = 1;
  usleep(50000);
}
