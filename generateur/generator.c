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

void	write_map(t_map *map, int height, int width, int fd_file)
{
  int	i;
  int	j;
  int	line;

  i = 0;
  j = 0;
  line = 0;
  while (line < height)
    {
      while (j < width)
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

t_map	*move_up(t_map *map, int *coord, int width)
{
  if (map[*coord].line > 1)
    {
      *coord = *coord - width;
      if (map[*coord].index == 2)
	return (map);
      map[*coord].index = 1;
    }
  return (map);
}

t_map	*move_right(t_map *map, int *coord, int width)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * width) - width));
      if (position < width -1)
	*coord = *coord + 1;
      if (map[*coord].index == 2)
	return (map);
      map[*coord].index = 1;
    }
  else if (*coord < width && map[*coord].line == 1)
    {
      *coord = *coord + 1;
      map[*coord].index = 1;
    }
  return (map);
}

t_map	*move_down(t_map *map, int *coord, int width, int height)
{
  if (map[*coord].line < height)
    {
      *coord = *coord + width;
      if (map[*coord].index == 2)
	return (map);
      map[*coord].index = 1;
    }
  return (map);
}

t_map	*move_left(t_map *map, int *coord, int width)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * width) - width));
      if (position > 0)
	*coord = *coord -1;
      if (map[*coord].index == 2)
	return (map);
      map[*coord].index = 1;
    }
  else if (*coord > 0 && map[*coord].line == 1)
    {
      *coord = *coord - 1;
      map[*coord].index = 1;
    }
  return (map);
}

t_map	*generator(t_map *map, int height, int width, int fd_file)
{
  int	coord;
  int	direction;

  coord = 0;
  while (map[coord].index != 2)
    {
      direction = rand() % 4;
      if (direction == UP)
	map = move_up(map, &coord, width);
      if (direction == RIGHT)
	map = move_right(map, &coord, width);
      if (direction == DOWN)
	map = move_down(map, &coord, width, height);
      if (direction == LEFT)
	map = move_left(map, &coord, width);
      if (map[coord].index == 2)
	{
	  map[coord].index = 2;
	  write_map(map, height, width, fd_file);
	  return (map);
	}
    }
  return (map);
}

int	main(int argc, char **argv)
{
  t_map	*map;
  int	fd_file;

  srand(time(0));
  if (argc > 1 && argc == 3)
    {
      fd_file = open("map.txt", O_CREAT | O_RDWR, 00644);
      map = create_map(atoi(argv[1]), atoi(argv[2]));
      map = generator(map, atoi(argv[1]), atoi(argv[2]), fd_file);
      close(fd_file);
      free(map);
    }
  else
    write(1, "./generateur [height] [width]\n", 30);
  return (0);
}
