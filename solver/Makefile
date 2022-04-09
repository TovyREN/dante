##
## EPITECH PROJECT, 2022
## dante
## File description:
## solver makefile
##

SRC	=	src/main.c	\
		src/check_map.c	\
		src/display_tab.c	\
		src/size.c	\
		src/solver.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-Iincludes

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY:	all clean fclean re
