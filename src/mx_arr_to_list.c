#include "path.h"

static void push_back(t_rib **node_r, char *isl1, char *isl2, int dist);
static t_rib *create_rib(char *isl1, char *isl2, int dist);
static void separator(char *str, char *i1, char *i2, int *d);
static int superlen(char *str, int *c2);

t_rib *mx_arr_to_list(char **arr, int i) {
    t_rib *new = NULL;

    for (i = 1; arr[i] != NULL; i++) {
        int c2 = 0;
        int c1 = superlen(arr[i], &c2);
        char *isl1 = mx_strnew(c1);
        char *isl2 = mx_strnew(c2);

        separator(arr[i], isl1, isl2, &c2);
        if (i == 1)
            new = create_rib(isl1, isl2, c2);
        else
            push_back(&new, isl1, isl2, c2);
    }
    return new;
}

static t_rib *create_rib(char *isl1, char *isl2, int dist) {
    t_rib *new_rib = malloc(sizeof(t_rib));
    new_rib->isl1 = isl1;
    new_rib->isl2 = isl2;
    new_rib->dist = dist;
    new_rib->next = NULL;
    return new_rib;
}

static void push_back(t_rib **node_r, char *isl1, char *isl2, int dist) {
    t_rib *n = *node_r;
    t_rib *node = create_rib(isl1, isl2, dist);
    while (n->next != NULL)
        n = n->next;
    n->next = node;
}
static int superlen(char *str, int *c2) {
    int c1 = *c2;
    while (*str != '-') {
        c1++;
        str++;
    }
    str++;
    while (*str != ',') {
        (*c2)++;
        str++;
    }
    return c1;
}

static void separator(char *str, char *i1, char *i2, int *d) {
    while (*str != '-') {
        *i1 = *str;
        i1++;
        str++;
    }
    str++;
    while (*str != ',') {
        *i2 = *str;
        i2++;
        str++;
    }
    str++;
    *d = mx_atoi(str);
}
