##
## makefile fed in the abyss
## rudreais
##
##

CFLAGS		+=		-I include -Wall -Wextra -W

LDFLAGS	+=		-lncurses

DIRLIB		+=		./lib/

DIRSRC		+=		./src/


SRC		+=		$(DIRLIB)maps.c		\
					$(DIRLIB)paths.c		\
					$(DIRLIB)readline.c	\
					$(DIRLIB)objects/*.c	\
					$(DIRSRC)main.c

OBJ		=		$(SRC:.c=.o)

EXEC		=		fita

all:				$(EXEC)

$(EXEC):			$(OBJ)
					$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS) $(CFLAGS)
					make clean
					mv $(EXEC) bin/

clean:
					rm -f $(OBJ)

fclean:			clean
					rm -f $(EXEC)

re:				clean all
