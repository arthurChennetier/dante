/*
** usefull.c for dante in /home/arthur/rendu/semestre2/initiation_ia/dante
** 
** Made by arthur
** Login   <chenne_a@epitech.net>
** 
** Started on  Wed Apr 27 14:44:56 2016 arthur
** Last update Tue May 17 17:39:07 2016 arthur
*/

#include <stdlib.h>
#include "maze.h"

int		my_strcmp(char *src, char *cmp)
{
  int		i;

  i = 0;
  if (my_strlen(src) != my_strlen(cmp))
    return (-1);
  while (src[i] != '\0')
    {
      if (src[i] != cmp[i])
	return (-1);
      i = i + 1;
    }
  return (1);
}

t_wall		init_wall(int height, int width)
{
  t_wall	wall;

  wall.nb = -1;
  wall.other = -1;
  wall.width = width;
  wall.height = height;
  return (wall);
}

t_create	*init_var(int width, int height)
{
  t_create	*var;

  if ((var = malloc(sizeof(t_create))) == NULL)
    return (NULL);
  if ((var->tab = init_tab(width, height)) == NULL)
    return (NULL);
  var->room = 1;
  var->i = 1;
  var->tab[0][0] = 1;
  var->tab[0][1] = 1;
  return (var);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int		my_getnbr(char *str)
{
  int		i;
  int		nbr;
  int		sign;

  i = 0;
  nbr = 0;
  sign = 1;
  while (str[i] < '0' || str[i] > '9')
    {
      if (str[i] == '\0')
	return (0);
      i = i + 1;
    }
  if (str[i - 1] == '-')
    sign = -1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      if (str[i] == '\0')
        return (nbr * sign);
      nbr = nbr * 10 + str[i] - '0';
      i = i + 1;
    }
  return (nbr * sign);
}
