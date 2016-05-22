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
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	check_dead_end(t_map *map, int coord, t_x_y direction)
{
  int	up;
  int	right;
  int	down;
  int	left;

  up = coord;
  right = coord;
  down = coord;
  left = coord;
  check_move_up(map, &up, direction);
  check_move_right(map, &right, direction);
  check_move_down(map, &down, direction);
  check_move_left(map, &left, direction);
  if (up == coord && right == coord && down == coord && left == coord)
    return (1);
  return (0);
}

char	*help_move(t_map *map, int *coord, t_x_y direct)
{
  int	i;
  int	dir;
  char	*move;

  i = 0;
  move = malloc(sizeof(char) * 5);
  dir = *coord;
  check_move_up(map, &dir, direct);
  if (dir != *coord)
    move[i++] = 'u';
  dir = *coord;
  check_move_right(map, &dir, direct);
  if (dir != *coord)
    move[i++] = 'r';
  dir = *coord;
  check_move_down(map, &dir, direct);
  if (dir != *coord)
    move[i++] = 'd';
  dir = *coord;
  check_move_left(map, &dir, direct);
  if (dir != *coord)
    move[i++] = 'l';
  move[i] = 0;
  return (move);
}

void	move(t_map *map, int *coord, int *count, t_x_y direct)
{
  int	direction;
  char	*dir;

  dir = help_move(map, coord, direct);
  direction = rand() % (strlen(dir));
  if (dir[direction] == 'u')
    map = move_up(map, coord, count, direct);
  if (dir[direction] == 'r')
    map = move_right(map, coord, count, direct);
  if (dir[direction] == 'd')
    map = move_down(map, coord, count, direct);
  if (dir[direction] == 'l')
    map = move_left(map, coord, count, direct);
  free(dir);
}
