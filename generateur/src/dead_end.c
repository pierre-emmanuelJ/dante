/*
** dead_end.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/src/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu May 19 17:35:35 2016 Pierre-Emmanuel Jacquier
** Last update Thu May 19 17:35:35 2016 Pierre-Emmanuel Jacquier
*/

#include "generator.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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
    map = move_left(map, coord, coun=t);
}
