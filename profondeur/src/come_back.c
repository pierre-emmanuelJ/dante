/*
** come_back.c for dante in /home/nico/rendu/S02/IA/dante/profondeur/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Fri May 27 17:29:53 2016 Nicolas Loriot
** Last update Fri May 27 17:30:50 2016 Nicolas Loriot
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
