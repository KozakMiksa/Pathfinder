#ifndef PATH_H
#define PATH_H

#include "libmx.h"

typedef struct rib
{
    char *isl1;
    char *isl2;
    int dist;
    struct rib *next;
} rib_t;

typedef struct path
{
	char *list;	
} path_t;

typedef struct turn {
    int turn;
    struct turn *next;
} turn_p;

char **mx_printerror(int argc, char *argv, char ***arr);
char **mx_deldub(char **arr1);
rib_t *mx_arr_to_list(char **arr);
path_t *mx_pathfinder(rib_t *list, char **orig, int size);
int **mx_creat_MX(int ***mx_W, turn_p ****mx_H, char **ar, rib_t *list);
void mx_deldub_l(turn_p ****mxH, int size);
void mx_fill_path(char **orig);

#endif
