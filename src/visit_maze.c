/*
** visit_maze.c for dante in /home/nico/rendu/S02/IA/dante/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Apr 29 15:35:51 2016 Nicolas Loriot
** Last update Thu May 12 11:56:58 2016 Nicolas Loriot
*/

#include "dante.h"

static t_stack	*get_newnode(t_stack *last)
{
  t_stack	*new;

  if (!(new = malloc(STACK_SIZE)) || !(new->coord = malloc(sizeof(int *) * 2)))
    exit(EXIT_FAILURE);
  if (last || last == NULL)
    {
      last = new;
      (new->next = malloc(STACK_SIZE)) ? (0) : (exit(EXIT_FAILURE));
      new->next = NULL;
    }
  else
    new->next = last;
  return (new);
}

t_stack		*pop(t_stack *last)
{
  /* last->next = last->next->next; */
  return (last->next);
}

t_stack		*add(t_stack *last, int x, int y)
{
  t_stack	*new;

  if (last)
    printf("x1=%d y1=%d\n", last->coord[0], last->coord[1]);
  new = get_newnode(last);
  new->visited = false;
  new->coord[0] = x;
  new->coord[1] = y;
  return (new);
}
