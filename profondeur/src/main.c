/*
** main.c for dante in /home/nico/rendu/S02/IA/dante/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Thu Apr 28 17:36:21 2016 Nicolas Loriot
** Last update Wed May 18 15:43:31 2016 Nicolas Loriot
*/

#include "dante.h"

static int	check_map(char *file)
{
  int		fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    perror("dante");
  return (fd);
}

static char	**read_file(int fd)
{
  char		**map;
  char		*s;
  struct stat	sb;
  int		i;

  if (fstat(fd, &sb) == -1)
    exit(EXIT_FAILURE);
  map = NULL;
  i = 0;
  while ((s = get_next_line(fd)))
    {
      (map = realloc(map, sizeof(char *) * (i + 2))) ? (0) : (exit(EXIT_FAILURE));
      (map[i] = strdup(s)) ? (0) : (exit(EXIT_FAILURE));
      free(s);
      i++;
    }
  map_width = strlen(map[i - 1]);
  map_height = i;
  map[i] = NULL;
  return (map);
}

int	main(int ac, char **av)
{
  char	**map;
  int	fd;

  if (ac != 2 || !(fd = check_map(av[1])))
    return (EXIT_FAILURE);
  map = read_file(fd);
  close(fd);
  resolve(map);
  return (0);
}
