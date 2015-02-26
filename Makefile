##
## Makefile for Makefile in /home/dulin_m/rendu/my_select
##
## Made by maxime dulin
## Login   <dulin_m@epitech.net>
##
## Started on  Tue Jan 14 11:22:34 2014 maxime dulin
## Last update Fri Feb  6 14:38:29 2015 Maxime DULIN
##

SRC	= main.c \
	gest_key.c \
	get_env.c \
	putstr_modif.c \
	my_modif_select.c \
	gest_opt.c \
	create_pipe.c \
	menu.c \
	ia.c \
	check_delete.c \
	cheat.c

NAME	= allum1

CC	= gcc

RM	= rm -f

OBJ	= $(SRC:.c=.o)

CFLAGS	=  -W -Wall -Wextra

LDFLAGS	= -lmy -L./My_lib/ -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

libmy:
	make -C ./My_lib/

libmyre:
	make -C ./My_lib/ re

fclean: clean
	$(RM) $(NAME)

re: fclean all
