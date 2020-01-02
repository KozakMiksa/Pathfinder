#include "path.h"

static void dell(t_route *route);

void mx_del_first_stack(t_stack **stack) {
    t_stack *Stack = *stack;

    if (Stack->next != NULL) {
        *stack = Stack->next;
        dell(Stack->route);
        free(Stack);
    }
    else {
        dell(Stack->route);
        free(Stack);
        *stack = NULL;
    }
}

static void dell(t_route *route) {
    t_route *tmp = route;

    while (route != NULL) {
        route = route->next;
        free(tmp);
        tmp = route;
    }
}
