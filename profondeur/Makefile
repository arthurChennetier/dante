##
## Makefile for BSQ in /home/chauvi_d/rendu/Prog_Elem/CPE_2015_BSQ
## 
## Made by Chauvin Antoine
## Login   <chauvi_d@epitech.net>
## 
## Started on  Mon Dec  7 14:19:51 2015 Chauvin Antoine
## Last update Tue May 31 22:22:45 2016 chauvi_d
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Werror -Wextra -Wall -I./ -I./include

LDFLAGS	=	-L./lib/my -lmy -L./lib/get_next_line

NAME	=	solver

SRCS	=	main.c \
		put_laby.c \
		check.c \
		my_free.c \
		check_init.c \

OBJS	=	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my/src
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)


clean:
	$(RM) $(OBJS)
	make clean -C ./lib/my/src

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/src

re: 	fclean all
