/*
** rm_noway.c for dante in /home/nico/rendu/S02/IA/dante/profondeur/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Fri May 27 17:06:55 2016 Nicolas Loriot
** Last update Fri May 27 19:01:20 2016 Nicolas Loriot
*/

#include "dante.h"

int	get_x_star(char **map, int *cur)
{
  if (map[cur[0] + 1] != NULL && map[cur[0] + 1][cur[1]] == '+')
    return (cur[0] + 1);
  else if (cur[0] > 0 && map[cur[0] - 1][cur[1]] == '+')
    return (cur[0] - 1);
  else
    return (cur[0]);
}

int	get_y_star(char **map, int *cur)
{
  if ((map[cur[0]][cur[1] + 1] != 0) && map[cur[0]][cur[1] + 1] == '+')
    return (cur[1] + 1);
  else if (cur[1] > 0 && map[cur[0]][cur[1] - 1] == '+')
    return (cur[1] - 1);
  else
    return (cur[1]);
}

int		*get_coord_star(char **map, int *cur)
{
  int		*tmp;

  if (!(tmp = malloc(sizeof(int) * 2)))
    exit(EXIT_FAILURE);
  tmp[0] = cur[0];
  tmp[1] = cur[1];
  if ((cur[0] = get_x_star(map, cur)) == tmp[0])
    {
      if ((cur[1] = get_y_star(map, tmp)) > 0)
	{
	  free(tmp);
	  return (cur);
	}
    }
  cur[0] = tmp[0];
  if ((cur[1] = get_y_star(map, tmp)) == tmp[1])
    {
      if ((cur[0] = get_x_star(map, tmp)) > 0)
	{
	  free(tmp);
	  return (cur);
	}
    }
  free(tmp);
  return (cur);
}

char		**clear_path(int *goal, char **map, int *cur)
{
  while (1)
    {
      if ((cur[0] - 1 == goal[0] && cur[1] == goal[1]) ||
	  (cur[0] + 1 == goal[0] && cur[1] == goal[1]) ||
	  (cur[0] == goal[0] && cur[1] + 1 == goal[1]) ||
	  (cur[0] == goal[0] && cur[1] - 1 == goal[1]))
	{
	  break ;
	}
      map[cur[0]][cur[1]] = '$';
      cur = get_coord_star(map, cur);
    }
  return (map);
}

