/*
** get_next_line.c for get_next_line in /home/chenne_a/rendu/CPE_2015_getnextline
** 
** Made by Arthur Chennetier
** Login   <chenne_a@epitech.net>
** 
** Started on  Mon Jan  4 09:34:19 2016 Arthur Chennetier
** Last update Mon Apr 11 14:19:09 2016 chauvi_d
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*check_read(int *i, int *size, int fd, char *buffer)
{
  if (*i == *size)
    {
      if ((*size = read(fd, buffer, READ_SIZE)) == -1 || *size == 0)
	{
	  free(buffer);
	  return (NULL);
	}
      *i = 0;
    }
  return (buffer);
}

char			get_char(const int fd)
{
  char	 		c;
  static int		i = 0;
  static int		size = -1;
  static char		*buffer;

  if (size == -1)
    {
      if ((buffer = malloc(sizeof(char) * READ_SIZE)) == NULL)
	return (-1);
      if ((size = read(fd, buffer, READ_SIZE)) == -1 || size == 0)
	{
	  free(buffer);
	  return (-1);
	}
    }
  if ((buffer = check_read(&i, &size, fd, buffer)) == NULL)
    return (-1);
  c = buffer[i];
  i = i + 1;
  if (c == '\n')
    return (0);
  return (c);
}

char			*get_next_line(const int fd)
{
  char			*res;
  int			i;
  static int		check = 0;

  i = 0;
  if (check == 1 || READ_SIZE < 1)
    return (NULL);
  if ((res = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  res[READ_SIZE] = '\0';
  while ((res[i] = get_char(fd)) != 0)
    {
      if (i % READ_SIZE == 0 && i != 0)
	res = my_realloc(res, READ_SIZE + i + 1);
      if (res[i] == -1)
	{
	  check = 1;
	  free(res);
	  return (NULL);
	}
      i = i + 1;
    }
  return (res);
}
