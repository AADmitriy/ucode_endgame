#include "virus.h"

bool mx_virus_catched_topi(t_topiman *topi) {
    if (topi->topi.x == topi->virus.x && topi->topi.y == topi->virus.y) {
        topi->is_winner = false;
        return true;
    }
    else {
        return false;
    }
}

