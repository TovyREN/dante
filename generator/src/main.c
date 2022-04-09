/*
** EPITECH PROJECT, 2022
** dante
** File description:
** generator main
*/

#include <time.h>
#include <stdlib.h>
#include "generator.h"
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
    if (ac == 3 && atoi(av[1]) > 0 && atoi(av[2]) > 0)
        generate_imperfect(atoi(av[1]), atoi(av[2]));
    if (ac == 4 && strcmp(av[3], "perfect") == 0) {
        srand(time(NULL));
        create_map(atoi(av[1]), atoi(av[2]));
    }
    return (0);
}
