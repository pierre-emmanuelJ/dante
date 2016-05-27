/*
** check_move.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Wed May 18 13:06:04 2016 Pierre-Emmanuel Jacquier
** Last update Wed May 18 13:06:04 2016 Pierre-Emmanuel Jacquier
*/

#include "generator.h"

void	check_move_up(t_map *map, int *coord, t_x_y direct)
{
  if (map[*coord].line > 2)
    {
      if (map[*coord - direct.x].index == 0
	  && map[*coord - (direct.x * 2)].index == 0)
	*coord = *coord - (direct.x * 2);
    }
}

void	check_move_right(t_map *map, int *coord, t_x_y direct)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * direct.x) - direct.x));
      if (position < direct.x -2
	  && map[*coord + 1].index == 0 && map[*coord + 2].index == 0)
	*coord = *coord + 2;
    }
  else if ((*coord < direct.x -1) && map[*coord].line == 1)
    {
      if (map[*coord + 1].index == 0
	  && map[*coord + 2].index == 0)
	*coord = *coord + 2;
    }
}

void	check_move_down(t_map *map, int *coord, t_x_y direct)
{
  if (map[*coord].line < direct.y -1)
    {
      if (map[*coord + direct.x].index == 0
	  && map[*coord + (direct.x * 2)].index == 0)
	*coord = *coord + (direct.x * 2);
    }
}

void	check_move_left(t_map *map, int *coord, t_x_y direct)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * direct.x) - direct.x));
      if (position > 1 && map[*coord - 1].index == 0 &&
	  map[*coord - 2].index == 0)
	*coord = *coord -2;
    }
  else if (*coord > 1 && map[*coord].line == 1)
    {
      if (map[*coord -1].index == 0 && map[*coord -2].index == 0)
	*coord = *coord - 2;
    }
}
