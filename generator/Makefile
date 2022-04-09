##
## EPITECH PROJECT, 2022
## dante
## File description:
## solver makefile
##

SRC	=	src/main.c	\
		src/perfect_map.c	\
		src/imperfect_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-Iincludes

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY:	all clean fclean re
