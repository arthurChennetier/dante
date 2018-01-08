/*
** my_putstr.c for my_putstr.c in /home/chauvi_d/rendu/day04
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Thu Oct  1 13:29:25 2015 Chauvin Antoine
** Last update Wed Jan 20 13:48:19 2016 Chauvin Antoine
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr_va(va_list ap)
{
  int nb_carac;
  char	*str;

  str = va_arg(ap, char*);
  if (str == NULL)
    return (0);
  nb_carac = 0;
  while (str[nb_carac] != '\0')
    {
      my_putchar(str[nb_carac]);
      nb_carac = nb_carac + 1;
    }
  return (0);
}
