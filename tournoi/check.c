/*
** check.c for profondeur in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante/profondeur
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Sun May 22 22:04:53 2016 chauvi_d
** Last update Tue May 31 17:16:14 2016 arthur
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int	*check_right(t_data *ctx, int pos, int *possi, int i)
{
  if (pos + 1 < ctx->size && ctx->laby[pos + 1] == '*')
    {
      ctx->nb_way++;
      possi[i] = pos + 1;
      i++;
    }
  return (possi);
}

int	*check_left(t_data *ctx, int pos, int *possi, int i)
{
  if (pos - 1 >= 0 && ctx->laby[pos - 1] == '*')
    {
      ctx->nb_way++;
      possi[i] = pos - 1;
      i++;
    }
  return (possi);
}

int	*check_down(t_data *ctx, int pos, int *possi, int i)
{
  if (pos + ctx->line < ctx->size && ctx->laby[pos + ctx->line] == '*')
    {
      ctx->nb_way++;
      possi[i] = pos + ctx->line;
      i++;
    }
  return (possi);
}

int	*check_up(t_data *ctx, int pos, int *possi, int i)
{
  if (pos - ctx->line >= 0 && ctx->laby[pos - ctx->line] == '*')
    {
      ctx->nb_way++;
      possi[i] = pos - ctx->line;
      i++;
    }
  return (possi);
}

t_tree	*check_laby(t_data *ctx, t_tree *tree)
{
  if (ctx->laby[tree->pos + 1] == 0)
    {
      tree->next = NULL;
      return (tree);
    }
  return (NULL);
}
