/*
** resolve.c for dante in /home/nico/rendu/S02/IA/dante/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Fri Apr 29 12:51:33 2016 Nicolas Loriot
** Last update Sun May 22 19:12:07 2016 Nicolas Loriot
*/

#include "dante.h"

int	get_x(char **map, int *cur)
{
  if (map[cur[0] + 1] != NULL && map[cur[0] + 1][cur[1]] == '*')
    return (cur[0] + 1);
  else if (cur[0] > 0 && map[cur[0] - 1][cur[1]] == '*')
    return (cur[0] - 1);
  else
    return (cur[0]);
}

int	get_y(char **map, int *cur)
{
  if ((map[cur[0]][cur[1] + 1] != 0) && map[cur[0]][cur[1] + 1] == '*')
    return (cur[1] + 1);
  else if (cur[1] > 0 && map[cur[0]][cur[1] - 1] == '*')
    return (cur[1] - 1);
  else
    return (cur[1]);
}

int		*get_coord(char **map, int *cur)
{
  int		*tmp;

  if (!(tmp = malloc(sizeof(int) * 2)))
    exit(EXIT_FAILURE);
  tmp[0] = cur[0];
  tmp[1] = cur[1];
  if ((cur[0] = get_x(map, cur)) == tmp[0])
    {
      if ((cur[1] = get_y(map, tmp)) > 0)
	return (cur);
    }
  cur[0] = tmp[0];
  if ((cur[1] = get_y(map, tmp)) == tmp[1])
    {
      if ((cur[0] = get_x(map, tmp)) > 0)
	return (cur);
    }
  free(tmp);
  return (cur);
}

void		resolve(char **map)
{
  t_queue	*top;
  int		*cur;
  int		*end;

  top = NULL;
  if (!(cur = malloc(sizeof(int) * 2)) || !(end = malloc(sizeof(int) * 2)))
    exit(EXIT_FAILURE);
  cur[0] = 0;
  cur[1] = 0;
  end = get_end_maze(map, end);
  bfs_v2(map, cur, end);
  free(cur);
  free(end);
  print_result(map, top);
}

void		print_result(char **map, t_queue *last)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (map[i][j] == '+')
	    printf("o");
	  else
	    putchar(map[i][j]);
	  j++;
	}
      putchar('\n');
      i++;
    }
  i = 0;
  free_queue(last);
  while (map[i])
    free(map[i++]);
  exit(EXIT_SUCCESS);
}
