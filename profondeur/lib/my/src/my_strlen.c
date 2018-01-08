/*
** my_strlen.c for my_strlen.c in /home/chauvi_d/rendu/day04
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Oct  1 16:34:28 2015 Chauvin Antoine
** Last update Wed Apr 27 18:19:03 2016 chauvi_d
*/

#include <unistd.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    count  = count + 1;
  return (count);
}

int	my_strlen_return(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\n' && str[count])
    count  = count + 1;
  return (count);
}

int	my_strlen2d(char **str)
{
  int	count;

  count = 0;
  while (str[count])
    count = count + 1;
  return (count - 1);
}
