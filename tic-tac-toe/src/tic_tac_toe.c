#include "tic_tac_toe.h"

int lp_ttt_play(int moves[]) {
    /* FIXME: REFACTOR */
    if((moves[0] == moves[1]) && (moves[0] > 0)) {
        return kLP_TTT_STATE_ILLEGAL_MOVE;
    }
    /* FIXME: REFACTOR */
    if(moves[1]) {
        return kLP_TTT_TURN_X;
    }
    /* FIXME: REFACTOR */
    if(moves[0]) {
        return kLP_TTT_TURN_O;
    }
    return kLP_TTT_TURN_X;
}
