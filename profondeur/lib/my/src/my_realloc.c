/*
** my_realloc.c for my_realloc in /home/chauvi_d/Rendu-2015-Epitech/rendu/Systunix/PSU_2015_minishell2/lib/my/src
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon Apr  4 16:07:45 2016 chauvi_d
** Last update Wed Apr 27 17:41:12 2016 chauvi_d
*/

#include "my.h"

char    *my_realloc(char *str, int size)
{
  char  *tmp;
  int   i;

  if (size == 0)
    {
      if (str != NULL)
        free(str);
      return (NULL);
    }
  i = 0;
  if ((tmp = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  if (str != NULL)
    {
      while (str[i] && i < size)
	{
	  tmp[i] = str[i];
	  i = i + 1;
	}
      free(str);
    }
  tmp[i] = 0;
  return (tmp);
}
