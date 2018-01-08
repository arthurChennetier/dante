/*
** libmy.h for libmy.h in /home/chauvi_d/rendu/Piscine_C_J07/lib/my
** 
** Made by Chauvin Antoine
** Login   <chauvi_d@epitech.net>
** 
** Started on  Wed Oct  7 16:15:53 2015 Chauvin Antoine
** Last update Wed Apr 27 18:19:18 2016 chauvi_d
*/

#ifndef	MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
# define ERROR_MSG "error\n"
# define SYNTAXE_ERROR_MSG "syntax error"

# ifndef                        READ_SIZE
#  define                        READ_SIZE (400)
# endif /* !READ_SIZE! */

typedef struct s_fonction
{
  char  flag;
  int   (*ptr)(va_list);
}              t_fonction;

char    *get_next_line(const int fd);
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
char	*my_realloc(char *str, int size);
char    *my_strcat(char *str1, char *str2);
char    *my_strcat_path(char *str1, char *str2);
void	free_2d(char **str);
int	my_strcmp(const char *str1, const char str2);
char	*word_tab_to_str(char **str);
char    *get_nb_words(char **str);
int     my_strlen2d(char **str);
char    *my_realloc(char *str, int size);
char	*my_strcpy(char *dest, char *src);
int     my_strncmp(const char *str1, const char *str2, int n);
char	*my_strcpy_path(char *dest, char *src);
int     my_strlen_return(char *str);

#endif /* !MY_H_ */
