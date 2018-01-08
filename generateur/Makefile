##
## Makefile for Makefile in /home/chenne_a/rendu/CPE_2015_Pushswap
## 
## Made by Arthur Chennetier
## Login   <chenne_a@epitech.net>
## 
## Started on  Mon Nov 16 14:15:36 2015 Arthur Chennetier
## Last update Sun May 22 23:36:26 2016 arthur
##

SRC	=	maze.c \
		usefull.c \
		fct_tab_maze.c \
		dig.c \
		node.c \
		refresh.c \
		imperfect.c

RM	=	rm -f

CC	=	gcc

TEMP	=	$(SRC:.c=.c~)

NAME	=	generateur

CFLAGS	=	-W -Wall -Werror -Wextra -I./include

LDFLAGS	=	-L./lib/print -lprint

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
