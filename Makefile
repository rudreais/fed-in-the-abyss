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

SRC		+=	$(DIRLIB)paths.c		\
    			$(DIRLIB)readline.c		\
			$(DIRLIB)objects/string.c	\
			$(DIRLIB)objects/o_strings.c	\
			$(DIRSRC)core/files.c		\
			$(DIRSRC)core/gen_map.c		\
			$(DIRSRC)prints.c		\
			$(DIRSRC)cursor.c		\
			$(DIRSRC)player.c		\
			$(DIRSRC)enemy.c		\
			$(DIRSRC)main.c

OBJ		=	$(SRC:.c=.o)

EXEC		=	fita

all:		$(EXEC)

$(EXEC):	$(OBJ)
		$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)
#		make clean
#		mv $(EXEC) bin/

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(EXEC)

re:		fclean all

.PHONY:		all clean fclean re
