/*
** move.c for dante in /home/jacqui_p/rendu/IA/dante/generateur/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Wed May 18 13:01:05 2016 Pierre-Emmanuel Jacquier
** Last update Wed May 18 13:01:05 2016 Pierre-Emmanuel Jacquier
*/

#include "generator.h"

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

static void	increment_coord(int *coord, t_map *map, int *count)
{
  *coord = *coord + 1;
  map[*coord].index = 1;
  *coord = *coord + 1;
  map[*coord].index = 1;
  *count = *count + 2;
}

t_map	*move_right(t_map *map, int *coord, int *count)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position < map[0].width -2
	  && map[*coord + 1].index == 0 && map[*coord + 2].index == 0)
	increment_coord(coord, map, count);
    }
  else if ((*coord < map[0].width -1) && map[*coord].line == 1)
    {
      if (map[*coord + 1].index == 0 && map[*coord + 2].index == 0)
	increment_coord(coord, map, count);
    }
  return (map);
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

t_map	*move_left(t_map *map, int *coord, int *count)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position > 1 && map[*coord - 1].index == 0 && map[*coord - 2].index == 0)
	decrement_coord(coord, map, count);
    }
  else if (*coord > 1 && map[*coord].line == 1)
    {
      if (map[*coord -1].index == 0 && map[*coord -2].index == 0)
	decrement_coord(coord, map, count);
    }
  return (map);
}
