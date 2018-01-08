/*
** my_revstr.c for RETURN in /home/chauvi_d/rendu/day06
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon Oct  5 11:01:09 2015 Chauvin Antoine
** Last update Mon Oct 26 12:29:19 2015 Chauvin Antoine
*/

char	*my_revstr(char *str)
{
  int	a;
  int	b;
  char	stock;

  a = 0;
  while (str[a])
    a = a + 1;
  b = 0;
  a = a - 1;
  while (a > b)
    {
      stock = str[b];
      str[b] = str[a];
      str[a] = stock;
      b = b + 1;
      a = a - 1;
    }
  return (str);
}
