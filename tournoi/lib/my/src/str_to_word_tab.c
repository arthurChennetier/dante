/*
** str_to_word_tab.c for  in /home/chauvi_d/rendu/Systunix/PSU_2015_my_exec
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Tue Jan  5 10:55:50 2016 Chauvin Antoine
** Last update Mon Apr 11 14:04:46 2016 chauvi_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

char	**get_nbwords(char *str, char divide)
{
  int	words;
  int	n;
  char	**array;

  words = 0;
  n = 0;
  while (str[n])
    {
      if (str[n] != divide && str[n] != '\t' && (str[n + 1] == divide
						 || str[n + 1] == 0
						 || str[n + 1] == '\t'))
	words = words + 1;
      n = n + 1;
    }
  if ((array = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  return (array);
}

char	*get_words(char *str, int n, int size, char divide)
{
  int	a;
  char	*arr;

  a = 0;
  if ((arr = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  if (size == 0)
    {
      arr = NULL;
      return (arr);
    }
  n = n - size;
  while (str[n] != divide && str[n] != '\t' && str[n] != 0)
    {
      arr[a] = str[n];
      a = a + 1;
      n = n + 1;
    }
  arr[a] = 0;
  return (arr);
}

char	*get_last(char *str, int n, int size)
{
  char	*arr;
  int	i;

  i = 0;
  if ((arr = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  if (size == 0)
    {
      arr = NULL;
      return (arr);
    }
  n = n - size;
  while (str[n])
    {
      arr[i] = str[n];
      n = n + 1;
      i = i + 1;
    }
  arr[i] = 0;
  return (arr);
}

char	**get_array(char **array, char divide, char *str)
{
  int	n;
  int	size;
  int	i;

  n = 0;
  size = 1;
  i = 0;
  while (str[n])
    {
      if ((str[n] == divide || str[n] == '\t') && str[n - 1] != divide
	  && str[n - 1] != '\t')
	{
	  array[i] = get_words(str, n, size, divide);
	  if (array[i][0] != 0)
	    i++;
	  size = 0;
	}
      if (str[n] != 0)
	n = n + 1;
      if (str[n] != divide && str[n] != '\t' && str[n] != 0)
	size = size + 1;
    }
  array[i] = get_last(str, n, size);
  (array[i] != NULL) ? (array[i + 1] = NULL) : (0);
  return (array);
}

char	**str_to_word_tab(char *str, char divide)
{
  char	**array;

  if (str == NULL)
    return (NULL);
  array = get_nbwords(str, divide);
  array = get_array(array, divide, str);
  return (array);
}
