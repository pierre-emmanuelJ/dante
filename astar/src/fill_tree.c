/*
** fill_tree.c for dante in /home/nico/rendu/S02/IA/dante/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Thu Apr 28 17:02:57 2016 Nicolas Loriot
** Last update Fri May 20 15:45:17 2016 Nicolas Loriot
*/

#include "dante.h"

unsigned int	get_nb_voisin(char **map, int x, int y)
{
  unsigned int	res;

  res = 0;
  if (map[x + 1] && map[x + 1][y] == '*')
    res += 1;
  if (map[x][y + 1] && map[x][y + 1] == '*')
    res += 1;
  if (x > 0 && map[x - 1][y] == '*')
    res += 1;
  if (y > 0 && map[x][y - 1] && map[x][y - 1] == '*')
    res += 1;
  return (res);
}

int		*get_end_maze(char **map, int *res)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (map[x])
    {
      while (map[x][y])
	y++;
      x++;
    }
  res[0] = x - 1;
  res[1] = y - 1;
  return (res);
}

t_queue		*fill_queue(t_queue *top, char **map, int *cur)
{
  if (map[cur[0]][cur[1] + 1] && map[cur[0]][cur[1] + 1] == '*')
    top = enqueue(top, cur[0], cur[1] + 1);
  if (map[cur[0] + 1] != NULL && map[cur[0] + 1][cur[1]] == '*')
    top = enqueue(top, cur[0] + 1, cur[1]);
  if (cur[1] > 0 && map[cur[0]][cur[1] - 1] == '*')
    top = enqueue(top, cur[0], cur[1] - 1);
  if (cur[0] > 0 && map[cur[0] - 1][cur[1]] == '*')
    top = enqueue(top, cur[0] - 1, cur[1]);
  return (top);
}

t_queue		*discover_vertex(char **map, int *cur, int *end, t_queue *q)
{
  int		nb_ways;

  while ((nb_ways = get_nb_voisin(map, cur[0], cur[1])) < 2)
    {
      if (!nb_ways)
	return (q);
      else if (cur[0] == end[0] && cur[1] == end[1])
	{
	  map[cur[0]][cur[1]] = '+';
	  return (NULL);
	}
      map[cur[0]][cur[1]] = '+';
      cur = get_coord(map, cur);
    }
  q = fill_queue(q, map, cur);
  return (q);
}

void		bfs_v2(char **map, int *cur, int *end)
{
  t_queue	*q;

  if (!(q = discover_vertex(map, cur, end, NULL)))
    return ;
  while (q)
    {
      map[q->coord[0]][q->coord[1]] = '+';
      if (!(q = discover_vertex(map, q->coord, end, q)))
	return ;
      q = dequeue(q);
    }
  map[end[0]][end[1]] = '+';
}
