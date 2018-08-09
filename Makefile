##
## makefile fed in the abyss
## rudreais
##
##

CC		=	gcc

CFLAGS		+=	-I $(DIRINC)	\
			-Wall -Wextra -W	\
			-g

LDFLAGS		+=	-lncurses

DIRLIB		+=	lib/

DIRSRC		+=	src/
DIRMAPS		+=	$(DIRSRC)maps/

DIRINC		+=	include/

SRC		+=	$(DIRLIB)my_snprintf.c		\
			$(DIRLIB)my_strcat.c		\
			$(DIRLIB)my_tabdup.c		\
			$(DIRLIB)my_str_to_word_array.c	\
			$(DIRSRC)main.c			\
			$(DIRSRC)level.c		\
			$(DIRSRC)game_loop.c		\
			$(DIRSRC)camera.c		\
			$(DIRSRC)move_charac.c		\
			$(DIRSRC)attack.c		\
			$(DIRSRC)screens/logs.c		\
			$(DIRSRC)screens/player_info.c	\
			$(DIRSRC)prints.c		\
			$(DIRSRC)player.c		\
			$(DIRSRC)enemy.c		\
			$(DIRMAPS)init_maps.c		\
			$(DIRMAPS)generate_maps.c	\
			$(DIRMAPS)destroy_maps.c

OBJ		=	$(SRC:.c=.o)

EXEC		=	fita

all:		$(EXEC)

$(EXEC):	$(OBJ)
		$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(EXEC)

re:		fclean all

.PHONY:		all clean fclean re
