#include "tic_tac_toe.h"

int lp_ttt_play(int previous_moves[], size_t moves_taken) {
    /* check for an illegal game in previous moves */
    if(lp_ttt_only_legal_moves(previous_moves, moves_taken) == -1) {
        return kLP_TTT_ILLEGAL_GAME_STATE;
    }

    /* figure out whos turn it is, X or O? */
    if((moves_taken % 2) == 0) {
        return kLP_TTT_TURN_X;
    }
    return kLP_TTT_TURN_O;
}

int lp_ttt_only_legal_moves(int previous_moves[], size_t moves_taken) {
    size_t current_move;
    int current_cell;
    int played_cells[kLP_TTT_MAX_MOVES];

    /* loop over previous moves, check for multiple moves of same cell */
    for(current_move = 0; current_move < moves_taken; ++current_move) {
        /* -1 for the current cell, arrays are zero indexed */
        current_cell = previous_moves[current_move] - 1;
        /* check if the cell has already been played; ie. an illegal move */
        if(played_cells[current_cell] == 1) {
            return -1;
        }
        /* first play of this cell, mark it as played */
        played_cells[current_cell] = 1;
    }
    return 0;
}