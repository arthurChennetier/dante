/*
** libmy.h for libmy.h in /home/chauvi_d/rendu/Piscine_C_J07/lib/my
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed Oct  7 16:15:53 2015 Chauvin Antoine
** Last update Tue May 31 22:23:02 2016 chauvi_d
*/

#ifndef	MY_H_
# define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
# define ERROR_MSG "error\n"
# define SYNTAXE_ERROR_MSG "syntax error"

# ifndef                        READ_SIZE
#  define                        READ_SIZE (400)
# endif /* !READ_SIZE! */

typedef struct	s_list
{
  char          *str;
  struct s_list	*next;
  struct s_list *prev;
}               t_list;

typedef struct	s_dlist
{
  size_t        length;
  t_list        *head;
}               t_dlist;

typedef struct s_builtins
{
  char		**arg;
  char		**env;
  char		*s;
  t_dlist	*list;
}              t_builtins;

typedef struct s_fonction
{
  char  flag;
  int   (*ptr)(va_list);
}              t_fonction;

typedef struct  s_tree
{
  int           pos;
  struct s_tree *next;
}               t_tree;

typedef struct  s_data
{
  int           line;
  int           size;
  int           nb_way;
  char          *laby;
  int           *way;
  int           *check;
  t_tree        *tree;
  int		i;
}               t_data;

char    *get_next_line(const int fd);
char    *my_realloc(char *str, int size);
int     my_putchar_va(va_list c);
int     my_putchar_pourcent(va_list);
int     my_put_nbr_va(va_list c);
int     my_put_nbrbase(int nb, char *base);
int     my_put_base(va_list c);
int     my_put_adress(va_list c);
int     my_put_unsbase(unsigned int nb, char *base);
int     my_put_oct(va_list c);
int     my_put_hex(va_list c);
int     my_put_hexup(va_list c);
int     my_put_bin(va_list c);
int     my_put_uns_va(va_list c);
int     my_putstr_va(va_list c);
int     my_putstr_ascii(va_list c);
int     my_printf(const char *format, ...);
void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	**str_to_word_tab(char *str, char CHAR);
char    *my_strcat(char *str1, char *str2);
char    *my_strcat_path(char *str1, char *str2);
void	free_2d(char **str);
char    *my_getenv(char **env, char *str);
char    *my_getpath(char *elem, char **path);
int	my_builtins(char *s, char **arg, char ***env);
int	my_strcmp(const char *str1, const char *str2);
void	my_free(char *str, char **arr);
char    *word_tab_to_str(char **str);
char    *get_nbwords(char **str);
int     my_strlen2d(char **str);
char	*my_strcpy(char *dest, char *src);
char	*my_strcpy_path(char *dest, char *src);
int     my_strncmp(const char *str1, const char *str2, int n);
int     my_strlen_return(char *str);

/* Solver */

char		*get_file(char *laby);
t_tree		*order_tree(t_tree *tree, int nb_way);
t_tree		*reset_tree(t_tree *tree);
t_tree		*create_tree(t_data *ctx);
t_tree		*get_tree(int pos, t_data *ctx);
t_data		*get_nb_way(int pos, t_data *ctx);
void		put_laby(t_tree *tree, char *laby);
int		*check_right(t_data *ctx, int pos, int *possi, int i);
int		*check_up(t_data *ctx, int pos, int *possi, int i);
int		*check_down(t_data *ctx, int pos, int *possi, int i);
int		*check_left(t_data *ctx, int pos, int *possi, int i);
void		my_freee(t_data *ctx);
t_tree		*check_laby(t_data *ctx, t_tree *tree);
t_data          *check_init(char *file);

#endif /* !MY_H_ */
