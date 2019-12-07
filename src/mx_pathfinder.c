#include "path.h"

static void mx_print_arr_int(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            mx_printint(arr[i][k]);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
    mx_printchar('\n');
}
static void mx_print_arr_int_of_3dmx(turn_p ***arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            while (arr[i][k] != NULL) {
                mx_printint(arr[i][k]->turn);
                mx_printchar(',');
                arr[i][k] = arr[i][k]->next;
            }
            mx_printstr("    ");
        }
        mx_printchar('\n');
    }
    mx_printchar('\n');
}

static turn_p *create(int turn);
static void pb_turn(turn_p **list, int turn);

path_t *mx_pathfinder(rib_t *list, char **orig, int size) {
    int **mxW = NULL;
    turn_p ***mxH = NULL;
    path_t *N = NULL;
    int V = 999999999;

    mx_creat_MX(&mxW, &mxH, orig, list);
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (mxW[i][j] > mxW[i][k] + mxW[k][j]) {
                    mxW[i][j] = mxW[i][k] + mxW[k][j];
                    mxH[i][j]->turn = mxH[i][k]->turn; 

                }
                if (mxW[i][j] == mxW[i][k] + mxW[k][j] && mxW[i][j] != 0 && mxW[i][k] != 0 && mxW[k][j] != 0 && mxW[i][j] != V && mxH[i][j]->turn != mxH[i][k]->turn) {
                    pb_turn(&mxH[i][j], k);
                    // mx_printstr("-----------------------\n");
                    // mx_printint(mxH[i][j]->turn);
                    // mx_printchar('\n');
                    // mx_printint(mxH[i][k]->turn);
                    // mx_printchar('\n');
                    // mx_printint(mxW[i][j]);
                    // mx_printchar('\n');
                    // mx_printint(mxW[i][k] + mxW[k][j]);
                    // mx_printchar('\n');
                }
                

            }
        }
    }
    mx_print_arr_int(mxW, size);
    mx_printstr("-----------------------\n");
    mx_print_arr_int_of_3dmx(mxH, size);
    return N;
}

static turn_p *create(int turn) {
    turn_p *list = malloc(sizeof(turn_p));

    list->turn = turn;
    list->next = NULL;
    return list;
}

static void pb_turn(turn_p **list, int turn) {
    turn_p *nlist = *list;
    turn_p *newl = create(turn);

    while (nlist->next != NULL)
        nlist = nlist->next;
    nlist->next = newl;
}
