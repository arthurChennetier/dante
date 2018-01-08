/*
** check_init.c for profondeur in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante/profondeur
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue May 31 22:14:16 2016 chauvi_d
** Last update Tue May 31 22:31:32 2016 chauvi_d
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int	check_rectangle(t_data *ctx)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  while (ctx->laby[i])
    {
      if (ctx->laby[i] == '\n' || ctx->laby[i + 1] == 0)
	{
	  if (ctx->laby[i + 1] == 0)
	    size++;
	  if (size != (ctx->line - 1))
	    {
	      my_printf("Error: Maze is not a rectangle\n");
	      return (-1);
	    }
	  size = -1;
	}
      i++;
      size++;
    }
  return (0);
}

t_data		*check_init(char *file)
{
  char		*laby;
  t_data	*ctx;

  if ((laby = get_file(file)) == NULL)
    return (NULL);
  if ((ctx = malloc(sizeof(t_data))) == NULL)
    return (NULL);
  ctx->i = 0;
  ctx->line = my_strlen_return(laby) + 1;
  ctx->size = my_strlen(laby) + 1;
  ctx->laby = laby;
  if (check_rectangle(ctx) == -1)
    return (NULL);
  if ((ctx->check = malloc(sizeof(int) * ctx->size)) == NULL)
    return (NULL);
  while (ctx->i != ctx->size)
    ctx->check[ctx->i++] = 0;
  return (ctx);
}
