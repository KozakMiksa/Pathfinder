#ifndef PATH_H
#define PATH_H

#include "libmx.h"

typedef struct s_rib {
    char *isl1;
    char *isl2;
    int dist;
    struct s_rib *next;
} t_rib;

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

char **mx_printerror(int argc, char *argv, char ***arr, int i);
char **mx_deldub(char **arr1);
t_rib *mx_arr_to_list(char **arr, int i);
void mx_pathfinder(t_rib *list, char **orig, int size);
void mx_creat_MX(int ***mx_W, char **ar, t_rib *list);
void mx_fill_path(t_route **route, int **mxW, char **orig);
t_adj **mx_adjacency(t_rib *list, char **orig, int size);
void mx_deep_search(t_adj **Adj, int **mxW, char **orig, int size);
void mx_stack(t_stack **stack, int next, int weight);
void mx_del_first_stack(t_stack **stack);
char *mx_arr_to_str(char **arr, char *str_new);

#endif
