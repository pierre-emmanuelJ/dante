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

void	help_move(t_map *map, int *coord, t_x_y direct, t_move_dir *move_dir)
{
  int	i;
  int	dir;

  i = 0;
  dir = *coord;
  check_move_up(map, &dir, direct);
  if (dir != *coord)
    move_dir->str[i++] = 'u';
  dir = *coord;
  check_move_right(map, &dir, direct);
  if (dir != *coord)
    move_dir->str[i++] = 'r';
  dir = *coord;
  check_move_down(map, &dir, direct);
  if (dir != *coord)
    move_dir->str[i++] = 'd';
  dir = *coord;
  check_move_left(map, &dir, direct);
  if (dir != *coord)
    move_dir->str[i++] = 'l';
  move_dir->str[i] = 0;
}

void	move(t_map *map, int *coord, int *count, t_x_y direct)
{
  int		direction;
  t_move_dir	move_dir;

  help_move(map, coord, direct, &move_dir);
  direction = rand() % (strlen(move_dir.str));
  if (move_dir.str[direction] == 'u')
    map = move_up(map, coord, count, direct);
  if (move_dir.str[direction] == 'r')
    map = move_right(map, coord, count, direct);
  if (move_dir.str[direction] == 'd')
    map = move_down(map, coord, count, direct);
  if (move_dir.str[direction] == 'l')
    map = move_left(map, coord, count, direct);
}
