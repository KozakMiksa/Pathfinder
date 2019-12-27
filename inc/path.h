#ifndef PATH_H
#define PATH_H

#include "libmx.h"

typedef struct rib {
    char *isl1;
    char *isl2;
    int dist;
    struct rib *next;
} rib_t;

typedef struct path {
    char *list;	
} path_t;

typedef struct s_adj {
    int to;
    int weight;
    struct  s_adj *next;
} t_adj;

typedef struct s_route {
    int point;
    struct s_route *next;
} t_route;

typedef struct s_stack {
	t_route *route;
	int next_point;
	int weight;
	struct s_stack *next;
} t_stack;

char **mx_printerror(int argc, char *argv, char ***arr);
char **mx_deldub(char **arr1);
rib_t *mx_arr_to_list(char **arr);
path_t *mx_pathfinder(rib_t *list, char **orig, int size);
void mx_creat_MX(int ***mx_W, char **ar, rib_t *list);
void mx_fill_path(char **orig); // not used
t_adj **mx_adjacency(rib_t *list, char **orig, int size);

#endif
