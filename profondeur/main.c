/*
** main.c for profondeur in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante/profondeur
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed Apr 27 17:11:36 2016 chauvi_d
** Last update Tue May 31 22:23:31 2016 chauvi_d
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

t_data	*get_nb_way(int pos, t_data *ctx)
{
  int	*possi;
  int	i;

  i = 0;
  ctx->nb_way = 0;
  if ((possi = malloc(sizeof(int) * 5)) == NULL)
    return (NULL);
  while (i != 5)
    {
      possi[i] = -1;
      i++;
    }
  i = 0;
  possi = check_right(ctx, pos, possi, i);
  if (possi[i] != -1)
    i++;
  possi = check_down(ctx, pos, possi, i);
  if (possi[i] != -1)
    i++;
  possi = check_left(ctx, pos, possi, i);
  if (possi[i] != -1)
    i++;
  possi = check_up(ctx, pos, possi, i);
  ctx->way = possi;
  return (ctx);
}

t_tree		*get_tree(int pos, t_data *ctx)
{
  t_tree	*tree;
  int		nb_way;
  int		i;
  int		*possi;

  i = 0;
  ctx = get_nb_way(pos, ctx);
  nb_way = ctx->nb_way;
  if (ctx->nb_way == 0 || ctx->check[pos] == 1)
    return (NULL);
  possi = ctx->way;
  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  tree->pos = pos;
  if (check_laby(ctx, tree) != NULL)
    return (tree);
  ctx->check[pos] = 1;
  while (nb_way-- != 0)
    if ((tree->next = get_tree(possi[i++], ctx)) != NULL)
      {
	free(possi);
	return (tree);
      }
  free(tree);
  return (NULL);
}

t_tree		*create_tree(t_data *ctx)
{
  t_tree	*tree;
  int		nb_way;
  int		i;
  int		*possi;

  i = 0;
  i = i;
  if ((tree = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  tree->pos = 0;
  ctx->check[0] = 1;
  ctx = get_nb_way(tree->pos, ctx);
  nb_way = ctx->nb_way;
  possi = ctx->way;
  while (nb_way-- != 0)
    {
      if ((tree->next = get_tree(possi[i], ctx)) != NULL)
	return (tree);
      i++;
    }
  return (NULL);
}

char	*get_file(char *laby)
{
  int	fd;
  char	*s;
  char	*buf;
  int	i;

  if ((s = malloc(sizeof(char) * 4096 + 1)) == NULL)
    return (NULL);
  if ((buf = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  if ((fd = open(laby, O_RDONLY)) == -1)
    return (NULL);
  while ((i = read(fd, s, 4096)) != 0)
    {
      s[i] = 0;
      buf = my_realloc(buf, my_strlen(s) + my_strlen(buf));
      buf = my_strcat(buf, s);
    }
  if (buf[my_strlen(buf) - 1] == '\n')
    buf[my_strlen(buf) - 1] = 0;
  buf[my_strlen(buf)] = 0;
  free(s);
  return (buf);
}

int	main(int ac, char **av)
{
  t_data	*ctx;

  if (ac != 2)
    {
      my_printf("Use : ./sover [file].txt\n");
      return (0);
    }
  if ((ctx = check_init(av[1])) == NULL)
    return (-1);
  ctx->tree = create_tree(ctx);
  put_laby(ctx->tree, ctx->laby);
  my_freee(ctx);
  return (0);
}
