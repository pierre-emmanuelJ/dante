/*
** generator.c for dante in /home/jacqui_p/rendu/IA/dante/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Apr 28 14:02:03 2016 Pierre-Emmanuel Jacquier
** Last update Thu Apr 28 14:02:03 2016 Pierre-Emmanuel Jacquier
*/

#include <unistd.h>
#include <stdlib.h>
#include "generator.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

void	display_map(t_map *map)
{
  int	i;
  int	j;
  int	line;

  i = 0;
  j = 0;
  line = 0;
  while (line < map[0].height)
    {
      while (j < map[0].width)
	{
	  if (map[i].index == 0)
	    printf("X");
	  else if (map[i].index == 1 || map[i].index == 2)
	    printf("\x1B[37m\x1B[44m*\x1B[0m");
	  j++;
	  i++;
	}
      printf("\n");
      j = 0;
      line++;
    }
}

void	write_map(t_map *map, int fd_file)
{
  int	i;
  int	j;
  int	line;

  i = 0;
  j = 0;
  line = 0;
  while (line < map[0].height)
    {
      while (j < map[0].width)
	{
	  if (map[i].index == 0)
	    write(fd_file, "X", 1);
	  else if (map[i].index == 1)
	    write(fd_file, "*", 1);
	  j++;
	  i++;
	}
      write(fd_file, "\n", 1);
      j = 0;
      line++;
    }
}

t_map	*move_up(t_map *map, int *coord, int *flag)
{
  if (map[*coord].line > 2)
    {
      if (map[*coord - map[0].width].index == 0 && map[*coord - (map[0].width * 2)].index == 0)
	{
	  *coord = *coord - map[0].width;
	  map[*coord].index = 1;
	  *coord = *coord - map[0].width;
	  map[*coord].index = 1;
	}
      if (map[*coord].index == 2)
	return (map);
    }
  return (map);
}

t_map	*move_right(t_map *map, int *coord, int *flag)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position < map[0].width -2 && map[*coord + 1].index == 0 && map[*coord + 2].index == 0)
	{
	  *coord = *coord + 1;
	  map[*coord].index = 1;
	  *coord = *coord + 1;
	  map[*coord].index = 1;
	}
      if (map[*coord].index == 2)
	return (map);
    }
  else if ((*coord < map[0].width -1) && map[*coord].line == 1)
    {
      if (map[*coord +1].index == 0 && map[*coord +2].index == 0)
	{
	  *coord = *coord + 1;
	  map[*coord].index = 1;
          *coord = *coord + 1;
	  map[*coord].index = 1;
	}
    }
  return (map);
}

t_map	*move_down(t_map *map, int *coord, int *flag)
{
  if (map[*coord].line < map[0].height -1)
    {
      if (map[*coord + map[0].width].index == 0 && map[*coord + (map[0].width * 2)].index == 0)
	{
	  *coord = *coord + map[0].width;
	  map[*coord].index = 1;
	  *coord = *coord + map[0].width;
	  map[*coord].index = 1;
	}
      if (map[*coord].index == 2)
	return (map);
    }
  return (map);
}

t_map	*move_left(t_map *map, int *coord, int *flag)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position > 1 && map[*coord - 1].index == 0 && map[*coord - 2].index == 0)
	{
	  *coord = *coord -1;
	  map[*coord].index = 1;
	  *coord = *coord -1;
	  map[*coord].index = 1;
	}
      if (map[*coord].index == 2)
	return (map);
    }
  else if (*coord > 1 && map[*coord].line == 1)
    {
      if (map[*coord -1].index == 0 && map[*coord -2].index == 0)
	{
	  *coord = *coord - 1;
	  map[*coord].index = 1;
          *coord = *coord - 1;
	  map[*coord].index = 1;
	}
      else
	*flag = *flag + 1;
    }
  return (map);
}

t_map	*generator(t_map *map, int fd_file)
{
  int	coord;
  int	direction;
  int	flag;

  coord = 0;
  flag = 0;
  while (map[coord].index != 2)
    {
      direction = rand() % 4;
      if (direction == UP)
	map = move_up(map, &coord, &flag);
      if (direction == RIGHT)
	map = move_right(map, &coord, &flag);
      if (direction == DOWN)
	map = move_down(map, &coord, &flag);
      if (direction == LEFT)
	map = move_left(map, &coord, &flag);
      if (flag >= 4)
	map = go_previous_star(map, &coord);
      display_map(map);
      printf("\n\n");
    }
  return (map);
}

int	main(int argc, char **argv)
{
  t_map	*map;
  int	fd_file;

  srand(time(NULL));
  if (argc > 1 && argc == 3)
    {
      fd_file = open("map.txt", O_CREAT | O_RDWR, 00644);
      map = create_map(atoi(argv[1]), atoi(argv[2]));
      map = generator(map, fd_file);
      close(fd_file);
      free(map);
    }
  else
    write(1, "./generateur [height] [width]\n", 30);
  return (0);
}
