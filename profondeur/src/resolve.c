/*
** resolve.c for dante in /home/nico/rendu/S02/IA/dante/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Fri Apr 29 12:51:33 2016 Nicolas Loriot
** Last update Wed May 18 14:26:50 2016 Nicolas Loriot
*/

#include "dante.h"

int	get_x(char **map, int *cur)
{
  if (map[cur[0] + 1] != NULL && map[cur[0] + 1][cur[1]] == '*')
    return (cur[0] + 1);
  else if (cur[0] > 0 && map[cur[0] - 1][cur[1]] == '*')
    return (cur[0] - 1);
  else if ((map[cur[0]][cur[1] + 1] && map[cur[0]][cur[1] + 1] == '*')
	   || (cur[1] > 0 && map[cur[0]][cur[1] - 1] == '*'))
    return (cur[0]);
  else
    return (-1);
}

int	get_y(char **map, int *cur)
{
  if ((map[cur[0]][cur[1] + 1] != 0) && map[cur[0]][cur[1] + 1] == '*')
    return (cur[1] + 1);
  else if (cur[1] > 0 && map[cur[0]][cur[1] - 1] == '*')
    return (cur[1] - 1);
  else if ((cur[0] > 0 && cur[0] + 1 < map_height) &&
	   (map[cur[0] + 1][cur[1]] == '*' || map[cur[0] - 1][cur[1]] == '*'))
    return (cur[1]);
  else
    return (-1);
}

int		*get_coord(char **map, int *cur)
{
  cur[0] = get_x(map, cur);
  cur[1] = get_y(map, cur);
  return (cur);
}

void		resolve(char **map)
{
  t_stack	*top;
  int		*cur;
  int		*end;

  top = NULL;
  if (!(cur = malloc(sizeof(int *) * 2)) || !(end = malloc(sizeof(int *) * 2)))
    exit(EXIT_FAILURE);
  cur[0] = 0;
  cur[1] = 0;
  end = get_end_maze(map);
  getaway(top, map, cur, end);
}

void		print_result(char **map)
{
  int		i;
  int		k;
  int		j;

  i = 0;
  j = 0;
  k = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (map[i][j] == '+')
	    putchar('o');
	  /* if (map[i][j] != 'X' || (map[i][j] != '*') || (map[i][j] != '+')) */
	  /*   putchar('o'); */
	  else
	    putchar(map[i][j]);
	  j++;
	}
      putchar('\n');
      i++;
    }
  while (map[k])
    free(map[k++]);
  exit(EXIT_SUCCESS);
}
