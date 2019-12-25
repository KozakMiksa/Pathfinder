#include "path.h"

static turn_p *create(int turn);
static void pb_turn(turn_p **list, int turn);

void mx_deldub_l(turn_p ****mxH, int size) {
    turn_p ***mxh = *mxH;
    turn_p *tmp = NULL;
    turn_p *tmpT = NULL;
    turn_p *tmpMXH = NULL;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            tmp = create(mxh[i][j]->turn);
            tmpT = tmp;
            tmpMXH = mxh[i][j];
            while (tmpMXH != NULL) {
                // while (tmp->next != NULL) {
                //     if (tmpMXH->turn != tmp->turn)
                //         tmp = tmp->next;
                // }
                if (tmp->turn != tmpMXH->turn)
                    pb_turn(&tmpT, tmpMXH->turn);
                tmp = tmpT;
                tmpMXH = tmpMXH->next;
            }
            mxh[i][j] = tmp;
        }
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
