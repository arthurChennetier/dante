/*
** refresh.c for dante in /home/arthur/rendu/semestre2/dante
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed May 11 15:22:52 2016 arthur
** Last update Wed May 11 16:42:06 2016 arthur
*/

#include "maze.h"

int		**quick_refresh(int **tab, t_wall var, int x, int y)
{
  tab[y][x] = var.nb;
  if (x + 1 < var.width)
    if (tab[y][x + 1] == var.other)
      tab = quick_refresh(tab, var, x + 1, y);
  if (x - 1 >= 0)
    if (tab[y][x - 1] == var.other)
      tab = quick_refresh(tab, var, x - 1, y);
  if (y + 1 < var.height)
    if (tab[y + 1][x] == var.other)
      tab = quick_refresh(tab, var, x, y + 1);
  if (y - 1 >= 0)
    if (tab[y - 1][x] == var.other)
      tab = quick_refresh(tab, var, x, y - 1);
  return (tab);
}

int		**refresh_tab(int **tab, t_wall var, t_pos pos)
{
  if (tab[pos.y][pos.x + 1] == var.other)
    tab = quick_refresh(tab, var, pos.x + 1, pos.y);
  if (tab[pos.y][pos.x - 1] == var.other)
    tab = quick_refresh(tab, var, pos.x - 1, pos.y);
  if (tab[pos.y + 1][pos.x] == var.other)
    tab = quick_refresh(tab, var, pos.x, pos.y + 1);
  if (tab[pos.y - 1][pos.x] == var.other)
    tab = quick_refresh(tab, var, pos.x, pos.y - 1);
  return (tab);
}

t_wall		right_check(int **tab, t_pos pos, t_wall var)
{
  var.other = var.nb;
  var.nb = tab[pos.y][pos.x + 1];
  return (var);
}

t_wall		up_check(int **tab, t_pos pos, t_wall var)
{
  var.other = var.nb;
  var.nb = tab[pos.y - 1][pos.x];
  return (var);
}
