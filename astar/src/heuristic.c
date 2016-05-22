/*
** heuristic.c for astar in /home/nico/rendu/S02/IA/dante/astar/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Fri May 20 17:38:48 2016 Nicolas Loriot
** Last update Sun May 22 16:46:37 2016 Nicolas Loriot
*/

#include "dante.h"

t_queue		*insert_mid(t_queue *q, int *cur, int prio)
{
  t_queue	*new;

  if (!(new = malloc(sizeof(t_queue))))
    exit(EXIT_FAILURE);
  new->coord[0] = cur[0];
  new->coord[1] = cur[1];
  new->prio = prio;
  new->visited = false;
  new->next = q;
  return (q);
}

t_queue		*enqueue_prio(t_queue *q, int x, int y, int prio)
{
  t_queue	*tmp;
  int		*cur;

  if (!q || prio <= q->prio)
    return (enqueue(q, x, y, prio));
  printf("q->prio = %d\nprio = %d\n", q->prio, prio);
  tmp = q;
  if (!(cur = malloc(sizeof(int) * 2)))
    exit(EXIT_FAILURE);
  cur[0] = x;
  cur[1] = y;
  while (q)
    {
      if (q->prio < prio)
	q = q->next;
      else
	break;
    }
  q = insert_mid(q, cur, prio);
  printf("tmp = %d\n", tmp->prio);
  return (tmp);
}

void	print_queue(t_queue *q)
{
  while (q)
    {
      printf("\nlist :\ncoord %d %d\nprio %d\n\n", q->coord[0], q->coord[1],
	     q->prio);
      q = q->next;
    }
}

int	taxicab(int x, int y, int *end)
{
  return (abs(x - end[0]) + abs(y - end[1]));
}
