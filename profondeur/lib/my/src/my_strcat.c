/*
** strcat.c for strcat.c in /home/chauvi_d/rendu/Systunix/PSU_2015_minishell1/lib/my/src
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Jan 19 18:28:46 2016 Chauvin Antoine
** Last update Wed Apr 27 17:35:09 2016 chauvi_d
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *str1, char *str2)
{
  char	*arr;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((arr = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1)))
      == NULL)
    return (NULL);
  while (str1[i])
    {
      arr[i] = str1[i];
      i++;
    }
  while (str2[j])
    arr[i++] = str2[j++];
  arr[i] = 0;
  return (arr);
}
