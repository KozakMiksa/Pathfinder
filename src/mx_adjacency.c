#include "path.h"

static int hesh(char **arr, char *str);
static t_adj *create(char *to, int weight, char **arr);
static void pb_turn(t_adj **list, char *to, int weight, char **arr);

t_adj **mx_adjacency(rib_t *list, char **orig, int size) {
    t_adj **adj = malloc(size * sizeof(t_adj *));
    int h = 0;

    for (int i = 0; i < size; i++)
        adj[i] = NULL;
    while (list != NULL) {
        h = hesh(orig, list->isl1);
        if (adj[h] == NULL)
            adj[h] = create(list->isl2, list->dist, orig);
        else
            pb_turn(&adj[h], list->isl2, list->dist, orig);
        h = hesh(orig, list->isl2);
        if (adj[h] == NULL)
            adj[h] = create(list->isl1, list->dist, orig);
        else
            pb_turn(&adj[h], list->isl1, list->dist, orig);
        list = list->next;
    }
    return adj;
}

static t_adj *create(char *to, int weight, char **arr) {
    t_adj *list = malloc(sizeof(t_adj));

    list->to = hesh(arr, to);
    list->weight = weight;
    list->next = NULL;
    return list;
}

static void pb_turn(t_adj **list, char *to, int weight, char **arr) {
    t_adj *nlist = *list;
    t_adj *newl = create(to, weight, arr);

    if (*list == NULL)
        *list = newl;
    while (nlist->next != NULL)
        nlist = nlist->next;
    nlist->next = newl;
}

static int hesh(char **arr, char *str) {
    int i = 0;
    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}
