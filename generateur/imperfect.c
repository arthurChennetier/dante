/*
** imperfect.c for dante in /home/arthur/rendu/semestre2/dante/generateur
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue May 17 17:48:09 2016 arthur
** Last update Sun May 22 23:36:09 2016 arthur
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "maze.h"

int		**make_imperfect(int **tab, int height, int width)
{
  int		x;
  int		y;
  int		count;
  int		r;

  y = 1;
  count = 0;
  while (y < height - 1)
    {
      r = rand() % 3;
      count = 0;
      x = 1;
      while (x < width - 1)
	{
	  if (tab[y][x] == -2)
	    count = count + 1;
	  if (count == r && tab[y][x] == -2)
	    tab[y][x] = 1;
	  x = x + 1;
	}
      y = y + 1;
    }
  return (tab);
}

int		imperfect(int height, int width)
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
  tab = make_imperfect(tab, height, width);
  maze = change_maze(maze, tab, width);
  write(1, maze, my_strlen(maze));
  my_free_all(tab, height, dig, maze);
  return (0);
}

