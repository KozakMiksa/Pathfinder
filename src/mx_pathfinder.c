#include "path.h"

static void floyd(int ***mxw, int size);

void mx_pathfinder(t_rib *list, char **orig, int size) {
    int **mxW = NULL;
    t_adj **adj = mx_adjacency(list, orig, size);

    mx_creat_MX(&mxW, orig, list);
    floyd(&mxW, size);
    mx_deep_search(adj, mxW, orig, size);
}

static void floyd(int ***mxw, int size) {
    int **mxW = *mxw;

    for (int k = 0; k < size; k++)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (mxW[i][j] > mxW[i][k] + mxW[k][j])
                    mxW[i][j] = mxW[i][k] + mxW[k][j];
}
