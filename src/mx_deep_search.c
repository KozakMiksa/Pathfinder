#include "path.h"

void mx_deep_search(t_adj **adj, int **mxW) {
    t_stack *stack_p = NULL;
    t_adj *tmp = adj;

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            creat_stack(&stack_p, i);
            while (stack_p != NULL) {
                if (stack_p->weight < mxW[i][j]) {
                    tmp = adj[stack_p->to];
                    while (adj[stack_p->to] != NULL) {    
                        stack(adj[stack_p->to], &stack_p);
                        adj[stack_p->to] = adj[stack_p->to]->next;
                    }
                    del_first_stack(&stack_p);
                    adj[stack_p->to] = tmp;
                }
                else if (stack_p->to != j || stack_p->weight > mxW[i][j])
                    del_first_stack(&stack_p);
                    else {
                        mx_fill_path(&stack_p);
                        del_first_stack(&stack_p);
                    }
        }
}
static t_stack *creat_stack(t_route *route, int next_point, int weight) {
    t_stack *stack_p = malloc(sizeof(t_stack *));

    creat_point(stack_p->path.point =);
    stack_p->next = NULL;
    return stack_p;
}

static void

static void stack(t_adj **adj, t_stack **stack_p) {
    
}

static void del_first_stack(t_stack stack_p) {
    
}
// static t_adj *create(char *to, int weight, char **arr) {
//     t_adj *list = malloc(sizeof(t_adj));

//     list->to = hesh(arr, to);
//     list->weight = weight;
//     list->next = NULL;
//     return list;
// }

// static void pb_turn(t_adj **list, char *to, int weight, char **arr) {
//     t_adj *nlist = *list;
//     t_adj *newl = create(to, weight, arr);

//     if (*list == NULL)
//         *list = newl;
//     while (nlist->next != NULL)
//         nlist = nlist->next;
//     nlist->next = newl;
// }