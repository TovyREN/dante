##
## EPITECH PROJECT, 2022
## dante
## File description:
## root makefile
##

all:	main

main:
	make -C solver/
	make -C generator/

clean:
	make -C solver/ clean
	make -C generator/ clean

fclean:	clean
	make -C solver/ fclean
	make -C generator/ fclean

re:	fclean all

.PHONY: all clean fclean re

tests_run:
	make -C solver/
	make -C generator/
