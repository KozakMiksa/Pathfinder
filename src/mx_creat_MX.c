#include "path.h"

static int hesh(char **arr, char *str);
static int **cr_mx_W(int size);
static void fill_mx(int ***arr_W, rib_t *list, char **ar);

void mx_creat_MX(int ***mx_W, char **ar, rib_t *list) {
    int size = 0;

    for (; ar[size] != NULL; size++);
    *mx_W = cr_mx_W(size);
    fill_mx(mx_W, list, ar);
}

static int **cr_mx_W(int size) {
    int inf = 999999999;
    int **matrix = malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
        for (int k = 0; k < size; k++) {
            if (i == k)
                matrix[i][k] = 0;
            else
                matrix[i][k] = inf;
        }
    }
    return matrix;
}

static int hesh(char **arr, char *str) {
    int i = 0;
    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}

static void fill_mx(int ***arr_W, rib_t *list, char **ar) {
    int **arr_w = *arr_W;

    while (list != NULL) {
        arr_w[hesh(ar, list->isl1)][hesh(ar, list->isl2)] = list->dist;
        arr_w[hesh(ar, list->isl2)][hesh(ar, list->isl1)] = list->dist;
        list = list->next;
    }
}
