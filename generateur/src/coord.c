/*
** coord.c for dante.c in /home/jacqui_p/rendu/IA/dante/generateur/src/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu May 19 17:59:14 2016 Pierre-Emmanuel Jacquier
** Last update Thu May 19 17:59:14 2016 Pierre-Emmanuel Jacquier
*/

#include "generator.h"

void	decrement_coord(int *coord, t_map *map, int *count)
{
  *coord = *coord - 1;
  map[*coord].index = 1;
  *coord = *coord - 1;
  map[*coord].index = 1;
  *count = *count + 2;
}
