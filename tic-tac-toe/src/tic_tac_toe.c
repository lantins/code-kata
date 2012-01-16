#include "tic_tac_toe.h"

int lp_ttt_play(int moves[]) {
    if(moves[0]) {
        return kLP_TTT_STATE_TURN_O;
    }
    return kLP_TTT_STATE_TURN_X;
}
