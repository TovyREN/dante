/*
** EPITECH PROJECT, 2022
** dante
** File description:
** solver include
*/

#ifndef SOLVER_H
    #define SOLVER_H

typedef struct pos_s{
    int x;
    int y;
}pos_t;

typedef struct map_s{
    char **map;
    pos_t *tp_pos;
    int count_tp;
    int pos_x;
    int pos_y;
    int width;
    int height;
}map_t;

void display_tab(map_t *map);
void do_backtracking(map_t *map);
char *read_map(char *filepath);
void init_map(char *buffer, map_t *map);
int check_map(char **map);
int size_of(char const *filepath);
int width_of(char *buffer);
int heigth_of(char *buffer);

#endif /* !SOLVER_H */
