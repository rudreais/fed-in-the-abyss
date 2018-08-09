##
## makefile fed in the abyss
## rudreais
##
##

CC		=	gcc

CFLAGS		+=	-I $(DIRINC)	\
			-Wall -Wextra -W	\
			-g

LDFLAGS		+=	-lncurses -lm

TESTFLAGS	+= -lcriterion

DIRLIB		+=	lib/

DIRSRC		+=	src/
DIRMAPS		+=	$(DIRSRC)maps/

DIRINC		+=	include/

DIRTEST		+=	src/test/

SRC		+=	$(DIRLIB)readline.c		\
			$(DIRLIB)my_snprintf.c		\
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

SRCTEST		+=	$(DIRLIB)readline.c		\
			$(DIRLIB)my_snprintf.c		\
			$(DIRLIB)my_strcat.c		\
			$(DIRLIB)my_tabdup.c		\
			$(DIRLIB)my_str_to_word_array.c	\
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
			$(DIRSRC)enemy.c		\
			$(DIRTEST)init_level_test.c

OBJ		=	$(SRC:.c=.o)

OBJTEST	=	$(SRCTEST:.c=.o)

EXEC		=	fita

EXECTEST	=	fita_test

all:		$(EXEC)

$(EXEC):	$(OBJ)
		$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

run_test:	$(OBJTEST)
			$(CC) -o $(EXECTEST) $(OBJTEST) $(LDFLAGS) $(TESTFLAGS)
			./$(EXECTEST)

clean:
		rm -f $(OBJ)
		rm -f $(OBJTEST)

fclean:		clean
		rm -f $(EXEC)
		rm -f $(EXECTEST)

re:		fclean all

.PHONY:		all clean fclean re
