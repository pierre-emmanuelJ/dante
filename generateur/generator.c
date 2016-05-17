/*
** gen_opti.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri May 13 14:24:53 2016 Pierre-Emmanuel Jacquier
** Last update Fri May 13 14:24:53 2016 Pierre-Emmanuel Jacquier
*/

#include <unistd.h>
#include <stdlib.h>
#include "generator.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void	display_map(t_map *map)
{
  int	i;
  int	j;
  int	line;

  i = 0;
  j = 0;
  line = 0;
  while (line < map[0].height)
    {
      while (j < map[0].width)
	{
	  if (map[i].index == 0)
	    printf("X");
	  else if (map[i].index == 1 || map[i].index == 2)
	    printf("\x1B[44m*\x1B[0m");
	  else if (map[i].index == 6)
	    printf("\x1B[41m*\x1B[0m");
	  j++;
	  i++;
	}
      printf("\n");
      j = 0;
      line++;
    }
}

t_map	*move_up(t_map *map, int *coord, int *count)
{
  if (map[*coord].line > 2)
    {
      if (map[*coord - map[0].width].index == 0
	  && map[*coord - (map[0].width * 2)].index == 0)
	{
	  *coord = *coord - map[0].width;
	  map[*coord].index = 1;
	  *coord = *coord - map[0].width;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_up(t_map *map, int *coord)
{
  if (map[*coord].line > 2)
    {
      if (map[*coord - map[0].width].index == 0
	  && map[*coord - (map[0].width * 2)].index == 0)
	*coord = *coord - (map[0].width * 2);
    }
}

t_map	*move_right(t_map *map, int *coord, int *count)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position < map[0].width -2
	  && map[*coord + 1].index == 0 && map[*coord + 2].index == 0)
	{
	  *coord = *coord + 1;
	  map[*coord].index = 1;
	  *coord = *coord + 1;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  else if ((*coord < map[0].width -1) && map[*coord].line == 1)
    {
      if (map[*coord +1].index == 0 && map[*coord +2].index == 0)
	{
	  *coord = *coord + 1;
	  map[*coord].index = 1;
          *coord = *coord + 1;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_right(t_map *map, int *coord)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position < map[0].width -2
	  && map[*coord + 1].index == 0 && map[*coord + 2].index == 0)
	*coord = *coord + 2;
    }
  else if ((*coord < map[0].width -1) && map[*coord].line == 1)
    {
      if (map[*coord +1].index == 0
	  && map[*coord +2].index == 0)
	*coord = *coord + 2;
    }
}

t_map	*move_down(t_map *map, int *coord, int *count)
{
  if (map[*coord].line < map[0].height -1)
    {
      if (map[*coord + map[0].width].index == 0
	  && map[*coord + (map[0].width * 2)].index == 0)
	{
	  *coord = *coord + map[0].width;
	  map[*coord].index = 1;
	  *coord = *coord + map[0].width;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_down(t_map *map, int *coord)
{
  if (map[*coord].line < map[0].height -1)
    {
      if (map[*coord + map[0].width].index == 0
	  && map[*coord + (map[0].width * 2)].index == 0)
	*coord = *coord + (map[0].width * 2);
    }
}

t_map	*move_left(t_map *map, int *coord, int *count)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position > 1 && map[*coord - 1].index == 0 && map[*coord - 2].index == 0)
	{
	  *coord = *coord -1;
	  map[*coord].index = 1;
	  *coord = *coord -1;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  else if (*coord > 1 && map[*coord].line == 1)
    {
      if (map[*coord -1].index == 0 && map[*coord -2].index == 0)
	{
	  *coord = *coord - 1;
	  map[*coord].index = 1;
          *coord = *coord - 1;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_left(t_map *map, int *coord)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position > 1 && map[*coord - 1].index == 0 && map[*coord - 2].index == 0)
	*coord = *coord -2;
    }
  else if (*coord > 1 && map[*coord].line == 1)
    {
      if (map[*coord -1].index == 0 && map[*coord -2].index == 0)
	*coord = *coord - 2;
    }
}

int	check_dead_end(t_map *map, int coord)
{
  int	up;
  int	right;
  int	down;
  int	left;

  up = coord;
  right = coord;
  down = coord;
  left = coord;
  check_move_up(map, &up);
  check_move_right(map, &right);
  check_move_down(map, &down);
  check_move_left(map, &left);
  if (up == coord && right == coord && down == coord && left == coord)
    return (1);
  return (0);
}

static t_map	*generator0(t_map *map, int stack_size)
{
  int	coord;
  int	direction;
  int	count;
  int	i;
  int	*stack;
  int	save;

  stack = malloc(sizeof(int) * stack_size + 1);
  i = 0;
  count = 1;
  coord = 0;
  while (count < stack_size)
    {
      save = coord;
      if (check_dead_end(map, coord) == 0)
	{
	  direction = rand() % 4;
	  if (direction == UP)
	    map = move_up(map, &coord, &count);
	  if (direction == RIGHT)
	    map = move_right(map, &coord, &count);
	  if (direction == DOWN)
	    map = move_down(map, &coord, &count);
	  if (direction == LEFT)
	    map = move_left(map, &coord, &count);
	}
      if (check_dead_end(map, coord) == 0 && save != coord)
	stack[i++] = coord;
      else if (check_dead_end(map, coord) == 1)
	{
	  if (i <= 0)
	    {
	      free (stack);
	      return (map);
	    }
	  i--;
	  while (check_dead_end(map, stack[i]) == 1 && i > 0)
	    i--;
	  coord = stack[i];
	}
    }
  free (stack);
  return (map);
}

t_map	*generator(t_map *map)
{
  return (generator0(map, map[0].width * (map[0].height / 2 + 1) + map[0].width / 2));
}

int	main(int argc, char **argv)
{
  t_map	*map;
  int	x;
  int	y;

  srand(time(NULL));
  if (argc > 1 && argc == 4)
    {
      x = atoi(argv[2]);
      y = atoi(argv[1]);
      if (x % 2 == 0)
	x--;
      if (y % 2 == 0)
	y--;
      if (string_equals(argv[3], "parfait") || string_equals(argv[3], "imparfait"))
	{
	  map = create_map(x, y);
	  generator(map);
	  if (string_equals(argv[3], "imparfait"))
	    printf("%s\n", "in construction !!");
	  display_map(map);
          free(map);
	}
      else
	write(1, "./generateur x y [parfait]\n", 27);
    }
  else
    write(1, "./generateur x y [parfait]\n", 27);
  return (0);
}
