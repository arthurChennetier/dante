/*
** free.c for profondeur in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante/profondeur
** 
** Made by chauvi_d
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed May 18 17:40:35 2016 chauvi_d
** Last update Wed May 18 17:54:51 2016 chauvi_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void    my_free_tree(t_tree *tree)
{
  t_tree        *tmp;
  t_tree        *next;

  tmp = tree;
  while (tmp != NULL)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
}
