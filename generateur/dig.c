/*
** dig.c for dante in /home/arthur/rendu/semestre2/dante
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Tue May 10 11:33:57 2016 arthur
** Last update Tue May 17 17:51:07 2016 arthur
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int		check_perfect(int **tab, t_dig *dig)
{
  t_pos		pos;
  int		nb;

  nb = -1;
  pos.x = dig->node->pos.x - 1;
  if (tab[dig->node->pos.y][pos.x] >= 0)
    nb = tab[dig->node->pos.y][pos.x];
  pos.x = dig->node->pos.x + 1;
  if (tab[dig->node->pos.y][pos.x] == nb && nb >= 0)
    return (-1);
  if (nb == -1 && tab[dig->node->pos.y][pos.x] >= 0)
    nb = tab[dig->node->pos.y][pos.x];
  pos.y = dig->node->pos.y - 1;
  if (tab[pos.y][dig->node->pos.x] == nb && nb >= 0)
    return (-1);
  if (nb == -1 && tab[pos.y][dig->node->pos.x] >= 0)
    nb = tab[pos.y][dig->node->pos.x];
  pos.y = dig->node->pos.y + 1;
  if (tab[pos.y][dig->node->pos.x] == nb && nb >= 0)
    return (-1);
  if (nb < 0)
    return (-1);
  return (1);
}

int		**break_wall(int **tab, t_pos pos, t_wall var)
{
  if ((tab[pos.y][pos.x - 1] < var.nb || var.nb == -1) &&
      tab[pos.y][pos.x - 1] >= 0)
    var.nb = tab[pos.y][pos.x - 1];
  else if (tab[pos.y][pos.x - 1] >= 0)
    var.other = tab[pos.y][pos.x - 1];
  if ((tab[pos.y][pos.x + 1] < var.nb || var.nb == -1) &&
      tab[pos.y][pos.x + 1] >= 0)
    var = right_check(tab, pos, var);
  else if (tab[pos.y][pos.x + 1] >= 0)
    var.other = tab[pos.y][pos.x + 1];
  if ((tab[pos.y - 1][pos.x] < var.nb || var.nb == -1) &&
      tab[pos.y - 1][pos.x] >= 0)
    var = up_check(tab, pos, var);
  else if (tab[pos.y - 1][pos.x] >= 0)
    var.other = tab[pos.y - 1][pos.x];
  if ((tab[pos.y + 1][pos.x] < var.nb || var.nb == -1) &&
      tab[pos.y + 1][pos.x] >= 0)
    {
      var.other = var.nb;
      var.nb = tab[pos.y + 1][pos.x];
    }
  else if (tab[pos.y + 1][pos.x] >= 0)
    var.other = tab[pos.y + 1][pos.x];
  tab[pos.y][pos.x] = var.nb;
  return (refresh_tab(tab, var, pos));
}

int		**last_correct(int **tab, int height, int width)
{
  if ((height % 2 == 0 && width % 2 == 1) ||
      (height % 2 == 1 && width % 2 == 0))
    {
      if (height > 1 && width > 1)
	if (tab[height - 2][width - 2] < 0)
	  tab[height - 2][width - 2] = 1;
    }
  if (height % 2 == 0 && width % 2 == 0)
    {
      if (height > 1 && width > 2)
	{
	  if (tab[height - 2][width - 2] < 0)
	    {
	      tab[height - 2][width - 2] = tab[height - 2][width - 3];
	      tab[height - 2][width - 3] = -1;
	    }
	}
    }
  return (tab);
}

int		**dig_path(int **tab, int height, int width, t_dig *dig)
{
  t_break	*tmp;
  t_wall	var;
  int		select;
  int		count;

  var = init_wall(height, width);
  while (dig->node != NULL)
    {
      select = rand() % 4;
      count = 0;
      while (count++ < select)
	dig->node = dig->node->next;
      tmp = dig->node;
      dig->node = dig->node->next;
      if (check_perfect(tab, dig) == 1)
	tab = break_wall(tab, dig->node->pos, var);
      dig->node = del_node(dig->node, tmp);
      dig->size = dig->size - 1;
    }
  tab = last_correct(tab, height, width);
  return (tab);
}
