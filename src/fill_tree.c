/*
** fill_tree.c for dante in /home/nico/rendu/S02/IA/dante/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Thu Apr 28 17:02:57 2016 Nicolas Loriot
** Last update Thu May 12 11:54:21 2016 Nicolas Loriot
*/

#include "dante.h"

unsigned int	get_nb_voisin(char **map, int x, int y)
{
  unsigned int	res;

  res = 0;
  if (map[x + 1][y] && map[x + 1][y] == '*')
    res += 1;
  if (map[x][y + 1] && map[x][y + 1] == '*')
    res += 1;
  if (x > 0 && map[x - 1][y] == '*')
    res += 1;
  if (y > 0 && map[x][y - 1] && map[x][y - 1] == '*')
    res += 1;
  return (res);
}

int		*get_end_maze(char **map)
{
  int		x;
  int		y;
  int		*res;

  x = 0;
  y = 0;
  if (!(res = malloc(sizeof(int *) * 2)))
    exit(EXIT_FAILURE);
  while (map[x])
    {
      while (map[x][y])
	y++;
      x++;
    }
  res[0] = x;
  res[1] = y;
  return (res);
}

t_stack		*fill_stack(t_stack *top, char **map, int *cur)
{
  if (map[cur[0]][cur[1] + 1] == '*')
    top = add(top, cur[0], cur[1] + 1);
  if (map[cur[0] + 1][cur[1]] == '*')
    top = add(top, cur[0] + 1, cur[1]);
  if (cur[1] > 0 && map[cur[0]][cur[1] - 1] == '*')
    top = add(top, cur[0], cur[1] - 1);
  if (cur[0] > 0 && map[cur[0] - 1][cur[1]] == '*')
    top = add(top, cur[0] - 1, cur[1]);
  return (top);
}

void		getaway(t_stack *top, char **map, int *cur, int *end)
{
  unsigned int		nb_ways;

  if (top)
    {
      for (; top != NULL; top = top->next)
	printf("x=%d y=%d\n", cur[0], cur[1]);
    }
  if (end[0] == cur[0] && end[1] == cur[1])
    print_result(map);
  map[cur[0]][cur[1]] = '+';
  nb_ways = get_nb_voisin(map, cur[0], cur[1]);
  if (nb_ways > 1)
    {
      top = fill_stack(top, map, cur);
      getaway(pop(top), map, get_coord(map, cur), end);
    }
  else if (get_x(map, cur) == 0 && get_y(map, cur) == 0)
    getaway(top->next, map, top->coord, end);
  else
    getaway(top, map, get_coord(map, cur), end);
}
