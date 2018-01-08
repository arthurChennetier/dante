##
## Makefile for dante in /home/chauvi_d/Rendu-2015-Epitech/rendu/Initiation_Ia/dante
## 
## Made by chauvi_d
## Login   <chauvi_d@epitech.net>
## 
## Started on  Sun May 22 23:20:56 2016 chauvi_d
## Last update Wed Jun  1 15:51:36 2016 chauvi_d
##

all:		recursive

recursive:
		make -C generateur
		make -C profondeur
		make -C tournoi

clean:
		make clean -C generateur
		make clean -C profondeur
		make clean -C tournoi

fclean:         clean
		make fclean -C generateur
		make fclean -C profondeur
		make fclean -C tournoi

re:             fclean all
