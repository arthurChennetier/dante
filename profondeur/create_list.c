/*
** create_tree.c for profondeur in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante/profondeur
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon May  2 11:15:40 2016 chauvi_d
** Last update Sun May 22 22:19:34 2016 chauvi_d
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

t_liste		*get_list(t_tree *tree, char *laby)
{
  t_liste	*elem;
  int		i;

  i = 0;
  if (tree->mark == true)
    return (NULL);
  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  elem->pos = tree->pos;
  tree->mark = true;
  if (laby[tree->pos + 1] == 0)
    {
      elem->next = NULL;
      return (elem);
    }
  while (tree->next[i] && tree->next)
    {
      if ((elem->next = get_list(tree->next[i], laby)) != NULL)
	return (elem);
      i++;
    }
  return (NULL);
}

t_dliste	*create_list(t_data *ctx)
{
  t_dliste	*list;
  t_liste	*elem;
  int		i;

  i = 0;
  if (ctx->laby[0] == 'X' && ctx->laby[my_strlen(ctx->laby)] == 'X' )
    return (NULL);
  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if ((list = malloc(sizeof(t_dlist))) == NULL)
    return (NULL);
  list->length = 0;
  list->head = elem;
  elem->pos = 0;
  if ((elem->next = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  while (ctx->tree->next[i] && ctx->tree->next)
    {
      if ((elem->next = get_list(ctx->tree->next[i++], ctx->laby)) != NULL)
	return (list);
      ctx->tree = reset_tree(ctx->tree);
    }
  if (elem->next == NULL)
    return (NULL);
  return (list);
}
