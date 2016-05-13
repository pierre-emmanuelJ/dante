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
	  else if (map[i].index == 6)
	    printf("\x1B[31m\x1B[41m*\x1B[0m");
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

t_map	*move_up(t_map *map, int *coord, int *count)
{
  if (map[*coord].line > 2)
    {
      if (map[*coord - map[0].width].index == 0 && map[*coord - (map[0].width * 2)].index == 0)
	{
	  *coord = *coord - map[0].width;
	  map[*coord].index = 1;
	  *coord = *coord - map[0].width;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_up(t_map *map, int *coord)
{
  if (map[*coord].line > 2)
    {
      if (map[*coord - map[0].width].index == 0 && map[*coord - (map[0].width * 2)].index == 0)
	*coord = *coord - (map[0].width * 2);
    }
}

t_map	*move_right(t_map *map, int *coord, int *count)
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
	  *count = *count + 2;
	}
    }
  else if ((*coord < map[0].width -1) && map[*coord].line == 1)
    {
      if (map[*coord +1].index == 0 && map[*coord +2].index == 0)
	{
	  *coord = *coord + 1;
	  map[*coord].index = 1;
          *coord = *coord + 1;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_right(t_map *map, int *coord)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position < map[0].width -2 && map[*coord + 1].index == 0 && map[*coord + 2].index == 0)
	*coord = *coord + 2;
    }
  else if ((*coord < map[0].width -1) && map[*coord].line == 1)
    {
      if (map[*coord +1].index == 0 && map[*coord +2].index == 0)
	*coord = *coord + 2;
    }
}

t_map	*move_down(t_map *map, int *coord, int *count)
{
  if (map[*coord].line < map[0].height -1)
    {
      if (map[*coord + map[0].width].index == 0 && map[*coord + (map[0].width * 2)].index == 0)
	{
	  *coord = *coord + map[0].width;
	  map[*coord].index = 1;
	  *coord = *coord + map[0].width;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_down(t_map *map, int *coord)
{
  if (map[*coord].line < map[0].height -1)
    {
      if (map[*coord + map[0].width].index == 0 && map[*coord + (map[0].width * 2)].index == 0)
	*coord = *coord + (map[0].width * 2);
    }
}

t_map	*move_left(t_map *map, int *coord, int *count)
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
	  *count = *count + 2;
	}
    }
  else if (*coord > 1 && map[*coord].line == 1)
    {
      if (map[*coord -1].index == 0 && map[*coord -2].index == 0)
	{
	  *coord = *coord - 1;
	  map[*coord].index = 1;
          *coord = *coord - 1;
	  map[*coord].index = 1;
	  *count = *count + 2;
	}
    }
  return (map);
}

void	check_move_left(t_map *map, int *coord)
{
  int	position;

  if (map[*coord].line > 1)
    {
      position = (*coord - ((map[*coord].line * map[0].width) - map[0].width));
      if (position > 1 && map[*coord - 1].index == 0 && map[*coord - 2].index == 0)
	*coord = *coord -2;
    }
  else if (*coord > 1 && map[*coord].line == 1)
    {
      if (map[*coord -1].index == 0 && map[*coord -2].index == 0)
	*coord = *coord - 2;
    }
}

int	try_up(t_map *map, int coord)
{
  if (map[coord].line > 2)
    {
      if (map[coord - map[0].width].index == 1 && map[coord - (map[0].width * 2)].index == 1)
	coord = coord - (map[0].width * 2);
    }
  return (coord);
}

int	try_right(t_map *map, int coord)
{
  int	position;

  if (map[coord].line > 1)
    {
      position = (coord - ((map[coord].line * map[0].width) - map[0].width));
      if (position < map[0].width -2 && map[coord + 1].index == 1 && map[coord + 2].index == 1)
	coord = coord + 2;
    }
  else if ((coord < map[0].width -1) && map[coord].line == 1)
    {
      if (map[coord +1].index == 1 && map[coord +2].index == 1)
	coord = coord + 2;
    }
  return (coord);
}

int	try_down(t_map *map, int coord)
{
  if (map[coord].line < map[0].height)
    {
      if (map[coord + map[0].width].index == 1 && map[coord + (map[0].width * 2)].index == 1)
	coord = coord + (map[0].width * 2);
    }
  return (coord);
}

int	try_left(t_map *map, int coord)
{
  int	position;

  if (map[coord].line > 1)
    {
      position = (coord - ((map[coord].line * map[0].width) - map[0].width));
      if (position > 1 && map[coord - 1].index == 1 && map[coord - 2].index == 1)
	coord = coord -2;
    }
  else if (coord > 1 && map[coord].line == 1)
    {
      if (map[coord -1].index == 1 && map[coord -2].index == 1)
	coord = coord - 2;
    }
  return (coord);
}

int	previous_star(t_map *map, int coord)
{
  int	pos;

  if (check_dead_end(map, coord))
    {
      pos = rand() % 4;
      if (pos == 0)
	coord = try_up(map, coord);
      if (pos == 1)
	coord = try_down(map, coord);
      if (pos == 2)
	coord = try_right(map, coord);
      if (pos == 3)
	coord = try_left(map, coord);
    }
  return (coord);
}

int	check_dead_end(t_map *map, int coord)
{
  int	up;
  int	right;
  int	down;
  int	left;

  up = coord;
  right = coord;
  down = coord;
  left = coord;
  check_move_up(map, &up);
  check_move_right(map, &right);
  check_move_down(map, &down);
  check_move_left(map, &left);
  if (up == coord && right == coord && down == coord && left == coord)
    return (1);
  return (0);
}

int	dead_end(t_map *map, int coord, int *flag)
{
  int	save;
  int	choice;
  int	flg;

  flg = 0;
  save = coord;
  if (try_right(map, coord) != save)
    flg = 1;
  if (try_left(map, coord) != save)
    flg = 2;
  if (check_dead_end(map, coord))
    {
      if ((coord = try_up(map, coord)) != save && *flag == 1)
	{
	  while (coord != save)
	    {
	      save = coord;
	      if ((try_left(map, coord)!= save) || (try_right(map, coord)!= save))
		{
		  choice = rand() % 3;
		  if (choice == 0)
		    coord = try_up(map, coord);
		  if (choice == 1)
		    {
		      coord = try_right(map, coord);
		      flg = 1;
		    }
		  if (choice == 2)
		    {
		      coord = try_left(map, coord);
		      flg = 2;
		    }
		}
	      coord = try_up(map, coord);
	    }
	}
      else if ((coord = try_down(map, coord)) != save)
	{
	  while (coord != save)
	    {
	      save = coord;
              if ((try_left(map, coord)!= save) || (try_right(map, coord)!= save))
		{
		  choice = rand() % 3;
		  if (choice == 0)
		    coord = try_up(map, coord);
		  if (choice == 1)
		    {
		      coord = try_right(map, coord);
		      flg = 1;
		    }
		  if (choice == 2)
		    {
		      coord = try_left(map, coord);
		      flg = 2;
		    }
		}
	      coord = try_down(map, coord);
	    }
	}
    }
  if (try_up(map, coord) != save)
    *flag = 1;
  if (try_down(map, coord) != save)
    *flag = 2;
  if (check_dead_end(map, coord))
    {
      save = coord;
      if ((coord = try_right(map, coord)) != save && flg == 1)
	{
	  while (coord != save)
	    {
	      save = coord;
	      if ((try_up(map, coord)!= save) || (try_down(map, coord)!= save))
		{
		  choice = rand() % 3;
		  if (choice == 0)
		    coord = try_right(map, coord);
		  if (choice == 1)
		    {
		      coord = try_down(map, coord);
		      *flag = 2;
		    }
		  if (choice == 2)
		    {
		      coord = try_up(map, coord);
		      *flag = 1;
		    }
		}
	      coord = try_right(map, coord);
	    }
	}
      else if ((coord = try_left(map, coord)) != save)
	{
	  while (coord != save)
	    {
	      save = coord;
	      if ((try_up(map, coord)!= save) || (try_down(map, coord)!= save))
		{
		  choice = rand() % 3;
		  if (choice == 0)
		    coord = try_right(map, coord);
		  if (choice == 1)
		    {
		      coord = try_down(map, coord);
		      *flag = 2;
		    }
		  if (choice == 2)
		    {
		      coord = try_up(map, coord);
		      *flag = 1;
		    }
		}
	      coord = try_left(map, coord);
	    }
	}
    }
  return (coord);
}

t_map	*generator(t_map *map, int fd_file)
{
  int	coord;
  int	direction;
  int	count;
  int	flag;

  flag = 0;
  count = 1;
  coord = 0;
  while (count < map[0].width * (map[0].height / 2 + 1) + map[0].width / 2)
    {
      direction = rand() % 4;
      if (direction == UP)
	map = move_up(map, &coord, &count);
      if (direction == RIGHT)
	map = move_right(map, &coord, &count);
      if (direction == DOWN)
	map = move_down(map, &coord, &count);
      if (direction == LEFT)
	map = move_left(map, &coord, &count);
      coord = dead_end(map, coord, &flag);

      map[coord].index = 6;
      display_map(map);
      printf("\n\n");
      map[coord].index = 1;
      usleep(50000);

    }
  return (map);
}

int	main(int argc, char **argv)
{
  t_map	*map;
  int	fd_file;
  int	x;
  int	y;
  int	i;

  i = 0;
  srand(time(NULL));
  if (argc > 1 && argc == 3)
    {
      fd_file = open("map.txt", O_CREAT | O_RDWR, 00644);
      x = atoi(argv[2]);
      y = atoi(argv[1]);
      if (x % 2 == 0)
	{
	  x--;
	  i++;
	}
      if (y % 2 == 0)
	{
	  y--;
	  i++;
	}
      map = create_map(x, y);
      map = generator(map, fd_file);
      display_map(map);
      close(fd_file);
      free(map);
    }
  else
    write(1, "./generateur x y [parfait]\n", 30);
  return (0);
}
