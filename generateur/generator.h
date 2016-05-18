/*
** generator.h for dante in /home/jacqui_p/rendu/IA/dante/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Apr 28 14:29:48 2016 Pierre-Emmanuel Jacquier
** Last update Thu Apr 28 14:29:48 2016 Pierre-Emmanuel Jacquier
*/
#ifndef GENERATOR_H_
# define GENERATOR_H_

# define UP	0
# define RIGHT	1
# define DOWN	2
# define LEFT	3

typedef	struct	s_map
{
  int		width;
  int		height;
  int		line;
  short int	index;
}		t_map;

t_map	*move_up(t_map *map, int *coord, int *count);
t_map	*move_right(t_map *map, int *coord, int *count);
t_map	*move_down(t_map *map, int *coord, int *count);
t_map	*move_left(t_map *map, int *coord, int *count);
void	check_move_up(t_map *map, int *coord);
void	check_move_right(t_map *map, int *coord);
void	check_move_down(t_map *map, int *coord);
void	check_move_left(t_map *map, int *coord);
int	string_equals(const char *a, const char *b);
int	check_dead_end(t_map *map, int coord);
t_map	*create_map(int height, int width);

#endif /* !GENERATOR_H_ */