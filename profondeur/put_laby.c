/*
** put_laby.c for profondeur in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante/profondeur
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Mon May  2 15:06:42 2016 chauvi_d
** Last update Wed Jun  1 15:50:46 2016 chauvi_d
*/

#include "my.h"

void	put_laby(t_tree *tree, char *laby)
{
  if (laby[0] == 'X' || laby[my_strlen(laby)] == 'X' || tree == NULL)
    my_printf("No solution found\n");
  else
    {
      while (tree != NULL)
	{
	  laby[tree->pos] = 'o';
	  tree = tree->next;
	}
      my_printf("%s", laby);
    }
}
