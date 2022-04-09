/*
** EPITECH PROJECT, 2022
** dante
** File description:
** main solver
*/

#include "solver.h"

int main(int ac, char **av)
{
    char *buffer = read_map(av[1]);
    map_t map;

    if (ac == 2) {
        init_map(buffer, &map);
        check_map(map.map);
        do_backtracking(&map);
    }
    return (0);
}
