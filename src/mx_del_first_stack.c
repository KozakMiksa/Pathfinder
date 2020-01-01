#include "path.h"

void mx_del_first_stack(t_stack **stack) {
    t_stack *Stack = *stack;

    if (Stack->next != NULL) {
        *stack = Stack->next;
        free(Stack);
    }
    else {
        free(Stack);
        *stack = NULL;
    }
}
