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

void	check_move_up(t_map *map, int *coord)
{
  if (map[*coord].line > 2)
    {
      if (map[*coord - map[0].width].index == 0
	  && map[*coord - (map[0].width * 2)].index == 0)
	*coord = *coord - (map[0].width * 2);
    }
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
      if (map[*coord + 1].index == 0
	  && map[*coord + 2].index == 0)
	*coord = *coord + 2;
    }
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
