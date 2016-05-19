/*
** create_map.c for dante in /home/jacqui_p/rendu/IA/dante/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Apr 28 15:44:03 2016 Pierre-Emmanuel Jacquier
** Last update Thu Apr 28 15:44:03 2016 Pierre-Emmanuel Jacquier
*/

#include <stdlib.h>
#include "generator.h"

static t_map	*fill_last_index(t_map *map, int last, int line)
{
  map[last].line = line;
  map[last].index = 0;
  return (map);
}

static t_map	*first(t_map *map, int height, int width)
{
  map[0].width = width;
  map[0].height = height;
  map[0].line = 1;
  map[0].index = 1;
  return (map);
}

static t_map	*fill_map(int i, int line, t_map *map)
{
  map[i].line = line;
  map[i].index = 0;
  return (map);
}

t_map	*create_map(int height, int width)
{
  int	i;
  int	line;
  int	count_index;
  t_map *map;

  i = 1;
  line = 1;
  count_index = 1;
  map = malloc(sizeof(t_map) * (height * width));
  map = first(map, height, width);
  while (line <= height)
    {
      while (count_index < width)
	{
	  if (line == height && i == (height * width) -1)
	    return (fill_last_index(map, (height * width) -1, line));
	  map = fill_map(i, line, map);
	  count_index++;
	  i++;
	}
      count_index = 0;
      line++;
    }
  return (map);
}
