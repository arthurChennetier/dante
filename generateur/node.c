/*
** dig.c for dante in /home/arthur/rendu/semestre2/dante
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon May  9 19:30:59 2016 arthur
** Last update Wed May 11 17:20:27 2016 arthur
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

t_break		*del_node(t_break *node, t_break *tmp)
{
  if (node->next == node)
    {
      free(node);
      return (NULL);
    }
  tmp->next = node->next;
  free(node);
  return (tmp);
}

t_pos		adapt_pos(int **tab, t_pos pos, int height, int width)
{
  if (pos.x == width)
    {
      pos.x = 0;
      pos.y = pos.y + 1;
    }
  if (pos.y >= height)
    return (pos);
  while (tab[pos.y][pos.x] != -1)
    {
      pos.x = pos.x + 1;
      if (pos.x == width)
	{
	  pos.x = 0;
	  pos.y = pos.y + 1;
	}
      if (pos.y >= height)
	return (pos);
    }
  return (pos);
}

int		prepare_circle(t_break *node)
{
  t_break	*tmp;
  int		size;

  size = 0;
  tmp = node;
  while (node->prev != NULL)
    {
      node = node->prev;
      size = size + 1;
    }
  tmp->next = node;
  node->prev = tmp;
  return (size + 1);
}

t_break		*prepare_node(int **tab, int height, int width, t_pos pos)
{
  t_break	*node;
  t_break	*tmp;

  pos = adapt_pos(tab, pos, height, width);
  node = malloc(sizeof(t_break));
  if (pos.y >= height || node == NULL)
    return (NULL);
  node->pos = pos;
  node->prev = NULL;
  pos = adapt_pos(tab, pos, height, width);
  while (pos.y < height)
    {
      if ((tmp = malloc(sizeof(t_break))) == NULL)
	return (NULL);
      tmp->pos = pos;
      tmp->prev = node;
      node->next = tmp;
      node = node->next;
      pos.x = pos.x + 1;
      tmp = NULL;
      pos = adapt_pos(tab, pos, height, width);
    }
  node->next = NULL;
  free(tmp);
  return (node);
}
