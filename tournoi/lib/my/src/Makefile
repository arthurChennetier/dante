##
## Makefile for Makefile in /home/chauvi_d/rendu/Piscine_C_J10/lib/my
## 
## Made by Chauvin Antoine
## Login   <chauvi_d@epitech.net>
## 
## Started on  Fri Oct  9 16:09:50 2015 Chauvin Antoine
## Last update Mon Apr  4 16:55:50 2016 chauvi_d
##

CC	= gcc

RM	= rm -f

CP	= cp

CFLAGS	+= -W -Wextra -Wall -Werror -ansi -pedantic -I./

LDFLAGS +=

NAME	= libmy.a

SRCS 	= my_printf.c\
          my_put_uns_va.c \
          my_put_nbr.c \
          my_putchar_va.c \
          my_putchar_pourcent.c \
          my_put_adress.c \
          my_put_nbr_va.c \
          my_put_nbrbase.c \
          my_put_base.c \
          my_put_unsbase.c \
          my_putstr_va.c \
          my_putstr_ascii.c \
	  my_strcat.c \
	  my_getnbr.c \
	  my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_revstr.c \
	  my_strlen.c \
	  str_to_word_tab.c \
	  free_2d.c \
	  my_strcmp.c \
	  word_tab_to_str.c \
	  my_realloc.c \
	  my_strcpy.c \
	  get_next_line.c \

OBJS	=	$(SRCS:.c=.o)

ARRC	=	ar rc

RANL	=	ranlib

all: copylib clean 

compil: $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	$(RANL) $(NAME)

copylib: compil
	$(CP) ./$(NAME) ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
