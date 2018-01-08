/*
** fct_tab.c for dante in /home/arthur/rendu/semestre2/initiation_ia/dante
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Thu Apr 28 13:32:25 2016 arthur
** Last update Wed May 11 17:05:10 2016 arthur
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int		**init_tab(int width, int height)
{
  int		**tab;
  int		i;
  int		j;

  if ((tab = malloc(sizeof(int*) * height)) == NULL)
    return (NULL);
  i = 0;
  while (i < height)
    {
      if ((tab[i++] = malloc(sizeof(int) * width)) == NULL)
	return (NULL);
    }
  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	tab[i][j++] = -2;
      i = i + 1;
    }
  return (tab);
}

char		*change_maze2(char *maze, int **tab, int i, t_pos pos)
{
  if (tab[pos.y][pos.x] == -1)
    maze[i] = 'X';
  else if (tab[pos.y][pos.x] == -2)
    maze[i] = 'X';
  else
    maze[i] = '*';
  return (maze);
}

char		*change_maze(char *maze, int **tab, int width)
{
  t_pos		pos;
  int		i;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (maze[i] != '\0')
    {
      if (pos.x == width)
	{
	  pos.x = 0;
	  pos.y = pos.y + 1;
	}
      maze = change_maze2(maze, tab, i, pos);
      i = i + 1;
      if (maze[i] == '\n')
	i = i + 1;
      pos.x = pos.x + 1;
    }
  return (maze);
}

char		*fill_maze(int width, int height)
{
  char		*maze;
  int		i;
  int		j;

  i = 0;
  if ((maze = malloc(sizeof(char) * (width * height + height + 1))) == NULL)
    return (NULL);
  while (i < width * height + height)
    {
      j = 0;
      while (j < width)
        {
          maze[i++] = 'X';
          j = j + 1;
        }
      if (i < width * height + height)
        maze[i++] = '\n';
    }
  maze[i - 1] = '\0';
  return (maze);
}

int		**create_room(int height, int width)
{
  t_create	*var;
  int		**new;
  t_pos		pos;

  pos.y = 0;
  if ((var = init_var(width, height)) == NULL)
    return (NULL);
  while (++pos.y < height - 1)
    {
      pos.x = 1;
      while (pos.x < width - 1)
	{
	  if ((pos.y % 2 == 0 && pos.x % 2 != 0) ||
	      (pos.y % 2 != 0 && pos.x % 2 == 0))
	    var->tab[pos.y][pos.x] = - 1;
	  else if (pos.y % 2 != 0 && pos.x % 2 != 0)
	    var->tab[pos.y][pos.x] = var->room++;
	  pos.x = pos.x + 1;
	}
    }
  var->tab[height - 2][width - 1] = var->room - 1;
  var->tab[height - 1][width - 1] = var->room - 1;
  new = var->tab;
  free(var);
  return (new);
}
