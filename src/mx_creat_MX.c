#include "path.h"

static int h(char **arr, char *str);
static int **cr_mx_W(int size);
static turn_p ***cr_mx_H(int size);
static void fill_mx(int ***arr_W, turn_p ****arr_H, rib_t *list, char **ar);

int **mx_creat_MX(int ***mx_W, turn_p ****mx_H, char **ar, rib_t *list) {
    int size = 0;
    int **mx_W_cp = NULL;

    for (; ar[size] != NULL; size++);
    *mx_W = cr_mx_W(size);
    mx_W_cp = cr_mx_W(size);
    *mx_H = cr_mx_H(size);
    fill_mx(mx_W, mx_H, list, ar);
    fill_mx(&mx_W_cp, mx_H, list, ar);
    return mx_W_cp;
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

static turn_p ***cr_mx_H(int size) {
    turn_p ***arr_h = malloc(size * sizeof(turn_p **));

    for (int i = 0; i < size; i++) 
        arr_h[i] = malloc(size * sizeof(turn_p *));
    for (int j = 0; j < size; j++) {
        for (int h = 0; h < size; h++) {
        arr_h[j][h] = malloc(sizeof(turn_p));
        arr_h[j][h]->turn = -1;
        arr_h[j][h]->next = NULL;
        }
    }
    return arr_h;
}

static int h(char **arr, char *str) {
    int i = 0;
    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}

static void fill_mx(int ***arr_W, turn_p ****arr_H, rib_t *list, char **ar) {
    int **arr_w = *arr_W;
    turn_p ***arr_h = *arr_H;

    while (list != NULL) {
        arr_w[h(ar, list->isl1)][h(ar, list->isl2)] = list->dist;
        arr_w[h(ar, list->isl2)][h(ar, list->isl1)] = list->dist;
        arr_h[h(ar, list->isl1)][h(ar, list->isl2)]->turn = h(ar, list->isl2);
        arr_h[h(ar, list->isl2)][h(ar, list->isl1)]->turn = h(ar, list->isl1);
        list = list->next;
    }
}
