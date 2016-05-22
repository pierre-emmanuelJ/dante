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
  int		line;
  short int	index;
}		t_map;

typedef	struct	s_x_y
{
  int		width;
  int		height;
  int		x;
  int		y;
  short int	live;
}		t_x_y;

t_map	*move_up(t_map *map, int *coord, int *count, t_x_y direct);
t_map	*move_right(t_map *map, int *coord, int *count, t_x_y direct);
t_map	*move_down(t_map *map, int *coord, int *count, t_x_y direct);
t_map	*move_left(t_map *map, int *coord, int *count, t_x_y direct);
t_map	*create_map(int height, int width, t_x_y coord);

void	decrement_coord(int *coord, t_map *map, int *count);
void	x_one_of_two(short int live, int width);
void	display_map(t_map *map, short int y, short int live, t_x_y direct);
void	x_y(t_x_y *coord, char **argv);
void	display_live(t_map *map, int coord, t_x_y direct);
void	move(t_map *map, int *coord, int *count, t_x_y direct);
void	perfect(char **argv, short int live, short int imparfait);
void	check_move_up(t_map *map, int *coord, t_x_y direct);
void	check_move_right(t_map *map, int *coord, t_x_y direct);
void	check_move_down(t_map *map, int *coord, t_x_y direct);
void	check_move_left(t_map *map, int *coord, t_x_y direct);

int	string_equals(const char *a, const char *b);
int	check_dead_end(t_map *map, int coord, t_x_y direction);

#endif /* !GENERATOR_H_ */
