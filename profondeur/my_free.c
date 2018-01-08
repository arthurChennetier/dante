/*
** my_free.c for profondeur in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante/profondeur
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun May 22 22:24:25 2016 chauvi_d
** Last update Sun May 22 22:49:15 2016 chauvi_d
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void	free_tree(t_tree *tree)
{
  t_tree	*next;
  t_tree	*tmp;

  tmp = tree;
  next = tmp->next;
  while (next != NULL)
    {
      free(tmp);
      tmp = next;
      next = tmp->next;
    }
}

void	my_freee(t_data *ctx)
{
  if (ctx->way != NULL)
    free(ctx->way);
  if (ctx->check != NULL)
    free(ctx->check);
  if (ctx->tree != NULL)
    free_tree(ctx->tree);
  free(ctx);
}
