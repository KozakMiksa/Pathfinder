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
	
} path_l;

char **mx_printerror(int argc, char *argv, char ***arr);
char **mx_deldub(char **arr1);
rib_t *mx_arr_to_list(char **arr);
path_l *mx_pathfinder(rib_t *list, char **orig);
void mx_creat_MX(int ***mx_W, int ***mx_H, int size);

#endif
