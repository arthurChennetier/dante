/*
** my_strcpy.c for my in /home/chenne_a/rendu/semestre2/PSU_2016/PSU_2015_tetris/lib/my/src
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Mar  7 12:24:18 2016 Arthur Chennetier
** Last update Mon Apr 11 14:08:46 2016 chauvi_d
*/

#include "my.h"

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  if (src == NULL)
    return (NULL);
  if (dest == NULL)
    if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
      return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_strcpy_path(char *dest, char *src)
{
  int		i;

  i = 0;
  if (src == NULL)
    return (NULL);
  if (dest == NULL)
    if ((dest = malloc(sizeof(char) * my_strlen(src) + 2)) == NULL)
      return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i++] = '=';
  dest[i] = 0;
  return (dest);
}
