#include "tic_tac_toe.h"

int lp_ttt_play(int moves[]) {
    if(moves[1]) {
        return kLP_TTT_TURN_X;
    }
    if(moves[0]) {
        return kLP_TTT_TURN_O;
    }
    return kLP_TTT_TURN_X;
}
