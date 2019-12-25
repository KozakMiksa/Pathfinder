#include "path.h"

// static void print_list(t_adj **adj, int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d\t", i);
//         while ((*adj) != NULL) {
//             printf("%d", (*adj)->to);
//             printf("%c", '|');
//             printf("%d", (*adj)->weight);
//             printf("%s", "-->");
//             (*adj) = (*adj)->next;
//         }
//         adj++;
//         printf("\n%s\n", "=====================");
//     }
// }

static void floyd(int ***mxw, int size);

path_t *mx_pathfinder(rib_t *list, char **orig, int size) {
    int **mxW = NULL;
    path_t *N = NULL;
    t_adj **adj = mx_adjacency(list, orig, size);

    mx_creat_MX(&mxW, orig, list);
    floyd(&mxW, size);
    // print_list(adj, size);


    return N;
}

static void floyd(int ***mxw, int size) {
    int **mxW = *mxw;

    for (int k = 0; k < size; k++)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (mxW[i][j] > mxW[i][k] + mxW[k][j])
                    mxW[i][j] = mxW[i][k] + mxW[k][j];
}
