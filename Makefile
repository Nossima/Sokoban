##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## BSQ
##

NAME= my_sokoban

SRC= main.c init_sokoban.c game_loop.c move_player.c move_box.c

OBJ= *.o #$(SRC:.c=.o)
MAIN_OBJ= $(MAIN_SRC:.c=.o)

RM=	rm -f
CC=	gcc -Wall -I./include

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ./lib/my
	$(CC) -g -c $(SRC)
	$(CC) -g -o $(NAME) $(OBJ) -L./lib/my -lmy -lncurses
	
clean:
	$(MAKE) -C ./lib/my clean
		rm -f $(OBJ)

fclean:	clean
	$(MAKE) -C ./lib/my fclean
	$(RM) $(NAME)

re: fclean all