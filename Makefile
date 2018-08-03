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

DIRINC		+=	include/

SRC		+=	$(DIRLIB)readline.c		\
			$(DIRLIB)my_snprintf.c		\
			$(DIRLIB)my_strcat.c		\
			$(DIRLIB)my_tabdup.c		\
			$(DIRLIB)my_str_to_word_array.c	\
			$(DIRSRC)main.c			\
			$(DIRSRC)init_level.c		\
			$(DIRSRC)destroy_level.c	\
			$(DIRSRC)game_loop.c		\
			$(DIRSRC)border_cam.c		\
			$(DIRSRC)move_charac.c		\
			$(DIRSRC)attack.c		\
			$(DIRSRC)core/init_maps.c	\
			$(DIRSRC)core/gen_map.c		\
			$(DIRSRC)screens/logs.c		\
			$(DIRSRC)screens/player_info.c	\
			$(DIRSRC)prints.c		\
			$(DIRSRC)player.c		\
			$(DIRSRC)enemy.c

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
