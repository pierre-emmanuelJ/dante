/*
** queue_op.c for dante in /home/nico/rendu/S02/IA/dante/largeur/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Thu May 19 14:32:12 2016 Nicolas Loriot
** Last update Sun May 22 22:17:27 2016 Nicolas Loriot
*/

#include "dante.h"

t_queue		*enqueue(t_queue *current, int x, int y, int prio)
{
  t_queue	*new;

  if (!(new = malloc(sizeof(t_queue))) ||
      !(new->coord = malloc(sizeof(int) * 2)))
    exit(EXIT_FAILURE);
  new->coord[0] = x;
  new->coord[1] = y;
  new->next = NULL;
  new->visited = false;
  new->prio = prio;
  if (!current)
    {
      new->tail = current;
      return (new);
    }
  new->next = current;
  new->tail = current->tail;
  return (new);
}

t_queue		*dequeue(t_queue *current)
{
  t_queue	*tmp;

  if (!current)
    return (NULL);
  tmp = current->next;
  while (current)
    current = current->next;
  free(current);
  return (tmp);
}

void		free_queue(t_queue *current)
{
  if (!current)
    return ;
  current = dequeue(current);
  if (current->next)
    free_queue(current->next);
}
