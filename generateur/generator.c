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

void	y_one_of_two(int live, short int *two)
{
  if (*two == 0)
    {
      if (live)
	printf("\x1B[44m*\x1B[0m");
      else
	printf("*");
      *two =+ 1;
    }
  else if (*two == 1)
    {
     if (live)
	printf("\x1B[37mX\x1B[0m");
      else
	printf("X");
      *two = 0;
    }
}

void	x_one_of_two(short int live, int width)
{
  int	i;

  i = 1;
  while (i < width)
    {
      if (live)
      printf("\x1B[37mX\x1B[0m");
      else
      printf("X");
      i++;
      if (live)
      printf("\x1B[44m*\x1B[0m");
      else
      printf("*");
      i++;
    }
  printf("\n");
}

void	display_map(t_map *map, short int y, short int live)
{
  int	i;
  int	j;
  int	line;
  short int	two;

  two = 0;
  i = 0;
  j = 0;
  line = 0;
  while (line < map[0].height)
    {
      while (j < map[0].width)
	{
	  if (live)
	    {
	      if (map[i].index == 0)
		printf("X");
	      else if (map[i].index == 1)
		printf("\x1B[44m*\x1B[0m");
	      else if (map[i].index == 6)
		printf("\x1B[41m*\x1B[0m");
	    }
	  else
	    {
	      if (map[i].index == 0)
		printf("X");
	      else if (map[i].index == 1)
		printf("*");
	    }
	  j++;
	  i++;
	}
      if (y)
	y_one_of_two(live, &two);
      printf("\n");
      j = 0;
      line++;
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

void	move(t_map *map, int *coord, int *count, int *save)
{
  int	direction;

  *save = *coord;
  direction = rand() % 4;
  if (direction == UP)
    map = move_up(map, coord, count);
  if (direction == RIGHT)
    map = move_right(map, coord, count);
  if (direction == DOWN)
    map = move_down(map, coord, count);
  if (direction == LEFT)
    map = move_left(map, coord, count);
}

void	display_live(t_map *map, int coord)
{
  map[coord].index = 6;
  display_map(map, 0, 1);
  printf("\n\n\n");
  map[coord].index = 1;
  usleep(10000);
}

static t_map	*generator0(t_map *map, int stack_size, int live)
{
  int	coord;
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
      move(map, &coord, &count, &save);
      if (check_dead_end(map, coord) == 0 && save != coord)
	stack[i++] = coord;
      else if (check_dead_end(map, coord) == 1)
	{
	  i--;
	  while (check_dead_end(map, stack[i]) == 1 && i > 0)
	    i--;
	  coord = stack[i];
	}
      if (live)
	display_live(map, coord);
    }
  free (stack);
  return (map);
}

t_map	*generator(t_map *map, int live)
{
  return (generator0(map, map[0].width *
		     (map[0].height / 2 + 1) + map[0].height / 2, live));
}

void	x_y(t_x_y *coord, char **argv)
{
  coord->x = atoi(argv[1]);
  coord->y = atoi(argv[2]);
  if (coord->x % 2 == 0)
    coord->x -= 1;
  if (coord->y % 2 == 0)
    coord->y -= 1;
}

void	unperfect(t_map *map, int total_wall)
{
  int	to_break;
  int	map_size;
  int	i;
  int	index;

  i = 0;
  map_size = map[0].width * map[0].height;
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
  map = create_map(coord.y, coord.x);
  generator(map, coord.live);
  if (imparfait)
    unperfect(map, map[0].width * (map[0].height / 2 + 1) + map[0].height / 2);
  if (coord.x < atoi(argv[1]))
    display_map(map, 1, coord.live);
  else if (coord.x == atoi(argv[1]))
    display_map(map, 0, coord.live);
  if (coord.x == atoi(argv[1]) && coord.y < atoi(argv[2]))
    {
      printf("X");
      x_one_of_two(coord.live, atoi(argv[1]));
    }
  else if (coord.y < atoi(argv[2]))
    x_one_of_two(coord.live, atoi(argv[1]));
  free(map);
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
