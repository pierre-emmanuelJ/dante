/*
** visit_maze.c for dante in /home/nico/rendu/S02/IA/dante/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Apr 29 15:35:51 2016 Nicolas Loriot
** Last update Thu May 19 12:28:25 2016 Nicolas Loriot
*/

#include "dante.h"

static t_stack	*get_newnode(t_stack *last)
{
  t_stack	*new;

  if (!(new = malloc(STACK_SIZE)) || !(new->coord = malloc(sizeof(int) * 2)))
    exit(EXIT_FAILURE);
  if (last == NULL)
    {
      last = new;
      new->next = NULL;
      return (new);
    }
  new->next = last;
  return (new);
}

t_stack		*pop(t_stack *top)
{
  t_stack	*tmp;

  tmp = top->next;
  free(top);
  return (tmp);
}

void		free_stack(t_stack *last)
{
  if (last == NULL)
    return ;
  free(last->coord);
  free_stack(last->next);
  free(last);
}

t_stack		*add(t_stack *last, int x, int y)
{
  t_stack	*new;

  new = get_newnode(last);
  new->visited = false;
  new->coord[0] = x;
  new->coord[1] = y;
  return (new);
}
