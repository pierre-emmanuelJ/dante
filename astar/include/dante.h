/*
** tree.h for dante in /home/nico/rendu/S02/IA/dante/inc
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Thu Apr 28 17:09:23 2016 Nicolas Loriot
** Last update Sun May 22 23:20:19 2016 Nicolas Loriot
*/

#ifndef TREE_H_
# define TREE_H_

/*
** LIB SYSTEME
*/

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
/*
** LIB PERSO
*/

# include "get_next_line.h"

/*
** STRUCT
*/

typedef struct		s_queue
{
  int			*coord;
  bool			visited;
  int			prio;
  struct s_queue	*next;
  struct s_queue	*tail;
}			t_queue;

int	map_height;
int	map_width;

# define STACK_SIZE (sizeof(t_stack))

/*
** PROTO
*/

void	resolve(char **map);
int	visit_left(char **map, int x, int y);
int	visit_right(char **map, int x, int y);
int	visit_down(char **map, int x, int y);
int	visit_up(char **map, int x, int y);
int	*get_coord(char **map, int *cur);
int	get_y(char **map, int *cur);
t_queue	*enqueue_prio(t_queue *q, int x, int y, int prio);
t_queue	*enqueue(t_queue *current, int x, int y, int prio);
t_queue	*dequeue(t_queue *current);
void	print_result(char **map);
int	taxicab(int x, int y, int *end);
int	*get_end_maze(char **map, int *end);
int	get_x(char **map, int *cur);
void	free_queue(t_queue *current);
void	astar(char **map, int *cur, int *end);
void	print_queue(t_queue *q);

#endif /* !TREE_H_ */
