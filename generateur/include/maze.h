/*
** maze.h for dante in /home/arthur/rendu/semestre2/initiation_ia/dante
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Apr 27 15:13:38 2016 arthur
** Last update Tue May 17 18:16:59 2016 arthur
*/

#ifndef MAZE_H_
# define MAZE_H_

typedef struct		s_create
{
  int			**tab;
  int			i;
  int			room;
  int			indic;
  int			s_indic;
}			t_create;

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_break
{
  t_pos			pos;
  struct s_break	*next;
  struct s_break	*prev;
}			t_break;

typedef struct		s_dig
{
  t_break		*node;
  int			size;
}			t_dig;

typedef struct		s_wall
{
  int			nb;
  int			other;
  int			width;
  int			height;
}			t_wall;

int             maze(int height, int width);
void            my_free_all(int **tab, int height, t_dig *dig, char *maze);
t_dig           *init_dig(t_break *node);
int             **last_correct(int **tab, int height, int width);
int             **break_wall(int **tab, t_pos pos, t_wall var);
int             imperfect(int height, int width);
t_wall          up_check(int **tab, t_pos pos, t_wall var);
t_wall          right_check(int **tab, t_pos pos, t_wall var);
int             **quick_refresh(int **tab, t_wall var, int x, int y);
int             **refresh_tab(int **tab, t_wall var, t_pos pos);
t_wall          init_wall(int height, int width);
t_break         *del_node(t_break *node, t_break *tmp);
int             **dig_path(int **tab, int height, int width, t_dig *dig);
t_pos           adapt_pos(int **tab, t_pos pos, int height, int width);
int		prepare_circle(t_break *node);
t_break         *prepare_node(int **tab, int height, int width, t_pos pos);
t_create        *init_var(int width, int height);
int             **create_room(int height, int width);
int             **init_tab(int width, int height);
char            *change_maze(char *maze, int **tab, int width);
char            *fill_maze(int width, int height);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int             my_strcmp(char *src, char *cmp);

#endif
