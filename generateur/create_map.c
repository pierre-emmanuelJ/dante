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

t_map	*fill_last_index(t_map *map, int last, int line)
{
  map[last].line = line;
  map[last].index = 2;
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
  map[0].line = 1;
  map[0].index = 1;
  while(line <= height)
    {
      while (count_index < width)
	{
	  if (line == height && i == (height * width) -1)
	    return (fill_last_index(map, (height * width) -1, line));
	  map[i].line = line;
	  map[i].index = 0;
	  count_index++;
	  i++;
	}
      count_index = 0;
      line++;
    }
  return (map);
}
