#include "path.h"

bool mx_CheckReturn(t_stack *stack_p, int to) {
    t_stack *st = stack_p;
    t_route *ro = st->route;;

    //if (ro->next != NULL)
        while (ro != NULL) {
        	if (ro->point == to)
        		return false;
            ro = ro->next;
        }
    // if (ro->point == to)
    //     return false;
    return true;
}
