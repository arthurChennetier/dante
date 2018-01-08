/*
** maze.c for dante in /home/arthur/rendu/semestre2/initiation_ia/dante
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Apr 27 14:44:29 2016 arthur
** Last update Sat May 28 14:12:53 2016 arthur
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "maze.h"

t_dig		*init_dig(t_break *node)
{
  t_dig		*dig;
  int		size;

  if ((dig = malloc(sizeof(t_dig))) == NULL)
    return (NULL);
  size = prepare_circle(node);
  dig->node = node;
  dig->size = size;
  return (dig);
}

void		my_free_all(int **tab, int height, t_dig *dig, char *maze)
{
  int		i;

  i = 0;
  free(dig->node);
  free(dig);
  free(maze);
  while (i < height)
    free(tab[i++]);
  free(tab);
}

int		maze(int height, int width)
{
  t_break	*node;
  t_dig		*dig;
  char		*maze;
  int		**tab;
  t_pos		pos;

  pos.x = 0;
  pos.y = 0;
  srand(time(NULL));
  if ((maze = fill_maze(width, height)) == NULL)
    return (-1);
  if ((tab = create_room(height, width)) == NULL)
    return (-1);
  if ((node = prepare_node(tab, height, width, pos)) == NULL)
    return (-1);
  if ((dig = init_dig(node)) == NULL)
    return (-1);
  tab = dig_path(tab, height, width, dig);
  maze = change_maze(maze, tab, width);
  write(1, maze, my_strlen(maze));
  my_free_all(tab, height, dig, maze);
  return (0);
}

void		check_imperfect(int height, int width)
{
  if (imperfect(width, height) == -1)
    write(1, "Malloc Problem during execution\n", 33);
}

int		main(int ac, char **av)
{
  int		width;
  int		height;

  if (ac == 4 || ac == 3)
    {
      width = my_getnbr(av[2]);
      height = my_getnbr(av[1]);
      if (height < 4 || width < 4)
	write(1, "Give Parameters > 4\n", 20);
      else if (ac == 4)
	{
	  if (my_strcmp(av[3], "parfait") == 1)
	    {
	      if (maze(width, height) == -1)
		write(1, "Malloc Problem during execution\n", 33);
	    }
	}
      else
	check_imperfect(height, width);
    }
  else
    write(1, "Usage : ./maze [width] [height] [parfait/imparfait]\n", 52);
  return (0);
}
