/*
** gen_opti.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Fri May 13 14:24:53 2016 Pierre-Emmanuel Jacquier
** Last update Fri May 13 14:24:53 2016 Pierre-Emmanuel Jacquier
*/

#include "generator.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	back_in_stack(int *i, int *stack, t_map *map, t_x_y direct)
{
  (*i)--;
  while (check_dead_end(map, stack[*i], direct) == 1 && *i > 0)
    (*i)--;
  return (stack[*i]);
}

static t_map	*generator0(t_map *map, int stack_size, int live, t_x_y direct)
{
  int	coord;
  int	count;
  int	i;
  int	*stack;

  stack = malloc(sizeof(int) * stack_size + 1);
  i = 0;
  count = 1;
  coord = 0;
  while (count < stack_size)
    {
      move(map, &coord, &count, direct);
      if (check_dead_end(map, coord, direct) == 0)
	stack[i++] = coord;
      else if (check_dead_end(map, coord, direct) == 1)
	coord = back_in_stack(&i, stack, map, direct);
      if (live)
	display_live(map, coord, direct);
    }
  free(stack);
  return (map);
}

t_map	*generator(t_map *map, int live, t_x_y coord)
{
  return (generator0(map, coord.x *
		     (coord.y / 2 + 1) + coord.y / 2, live, coord));
}

void	unperfect(t_map *map, const int total_wall, t_x_y coord)
{
  int	to_break;
  int	map_size;
  int	i;
  int	index;

  i = 0;
  map_size = coord.x * coord.y;
  to_break = (map_size - total_wall) / 4;
  while (i < to_break)
    {
      index = rand() % map_size;
      if (map[index].index == 0)
	{
	  map[index].index = 1;
	  i++;
	}
    }
}

void	perfect(char **argv, short int live, short int imparfait)
{
  t_map	*map;
  t_x_y	coord;

  x_y(&coord, argv);
  coord.live = live;
  map = create_map(coord.y, coord.x, coord);
  generator(map, coord.live, coord);
  if (imparfait)
    unperfect(map, coord.x * (coord.y / 2 + 1) + coord.y / 2, coord);
  if (coord.x < atoi(argv[1]))
    display_map(map, 1, coord.live, coord);
  else if (coord.x == atoi(argv[1]))
    display_map(map, 0, coord.live, coord);
  if (coord.x == atoi(argv[1]) && coord.y < atoi(argv[2]))
    {
      printf("X");
      x_one_of_two(coord.live, atoi(argv[1]));
    }
  else if (coord.y < atoi(argv[2]))
    x_one_of_two(coord.live, atoi(argv[1]));
  free(map);
}
