#include "libmx.h"
void mx_push_back(t_list **list, void *data)
{
    t_list *new_node = mx_create_node(data);
    t_list *s = *list;
    while(s->next != NULL)
    {
        s = s->next;
    }
    s->next = new_node;
}
