/*
** EPITECH PROJECT, 2022
** dante
** File description:
** generator includes
*/

#ifndef GENERATOR_H
    #define GENERATOR_H


char **create_map(int w, int h);
char **generate_imperfect(int w, int h);
char *one_out_of_two(char *map, int w);
char *fill_x(char *map, int w);

#endif /* !GENERATOR_H */
