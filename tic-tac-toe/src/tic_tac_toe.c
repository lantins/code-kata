#include "tic_tac_toe.h"

int lp_ttt_play(int previous_moves[], size_t moves_taken) {
    int winner;

    /* check for an illegal game in previous moves */
    if(lp_ttt_only_legal_moves(previous_moves, moves_taken) == -1) {
        return kLP_TTT_RC_ILLEGAL_GAME_STATE;
    }

    /* check for game over */
    winner = lp_ttt_win_draw_or_next_turn(previous_moves, moves_taken);
    switch(winner) {
        case 1: return kLP_TTT_RC_X_WIN;
        case 2: return kLP_TTT_RC_O_WIN;
        case 3: return kLP_TTT_RC_DRAW;
        default: break;
    }

    /* figure out whos turn it is, X or O? */
    if((moves_taken % 2) == 0) {
        return kLP_TTT_RC_NEXT_TURN_X;
    }
    return kLP_TTT_RC_NEXT_TURN_O;
}

int lp_ttt_only_legal_moves(int previous_moves[], size_t moves_taken) {
    size_t current_move;
    int current_cell;
    int played_cells[kLP_TTT_BOARD_CELLS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    /* loop over previous moves, check for multiple moves of same cell */
    for(current_move = 0; current_move < moves_taken; ++current_move) {
        /* -1 for the current cell, arrays are zero indexed */
        current_cell = previous_moves[(int)current_move] - 1;

        /* check if the cell has already been played; ie. an illegal move */
        if(played_cells[current_cell] == 1) {
            return -1;
        }
        /* first play of this cell, mark it as played */
        played_cells[current_cell] = 1;
    }

    /* no illegal moves found */
    return 0;
}

int lp_ttt_win_draw_or_next_turn(int previous_moves[], size_t moves_taken) {
    size_t current_move;
    int current_cell;
    int x_played[kLP_TTT_BOARD_CELLS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int o_played[kLP_TTT_BOARD_CELLS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    /* play each move one at a time, checking for winning moves */
    for(current_move = 0; current_move < moves_taken; ++current_move) {
        /* -1 for the current cell, arrays are zero indexed */
        current_cell = previous_moves[(int)current_move] - 1;

        /* who's turn is it, X or O? */
        if(current_move % 2) {
            /* O's turn */
            o_played[current_cell] = 1;
            if (lp_ttt_played_winning_moves(o_played)) { return 2; }
        } else {
            /* X's turn */
            x_played[current_cell] = 1;
            if (lp_ttt_played_winning_moves(x_played)) { return 1; }
        }
    }

    /* we have a draw */
    if(moves_taken == 9) { return 3; }

    /* no winner yet */
    return 0;
}

int lp_ttt_played_winning_moves(int played[]) {
    if (lp_ttt_played_winning_row(played)) { return 1; } /* check for a winning row */
    if (lp_ttt_played_winning_column(played)) { return 1; } /* check for a winning column */
    if (lp_ttt_played_winning_diagonal(played)) { return 1; } /* check for a winning diagonal */

    /* no winning moves played */
    return 0;
}

int lp_ttt_played_winning_row(int played[]) {
    if(played[0] && played[1] && played[2]) { return 1; } /* top row */
    if(played[3] && played[4] && played[5]) { return 1; } /* middle row */
    if(played[6] && played[7] && played[8]) { return 1; } /* bottom row */

    /* no winning row found */
    return 0;
}

int lp_ttt_played_winning_column(int played[]) {
    if(played[0] && played[3] && played[6]) { return 1; } /* left column */
    if(played[1] && played[4] && played[7]) { return 1; } /* centre column */
    if(played[2] && played[5] && played[8]) { return 1; } /* right column */

    /* no winning column found */
    return 0;
}

int lp_ttt_played_winning_diagonal(int played[]) {
    if(played[0] && played[4] && played[8]) { return 1; } /* top left to bottom right */
    if(played[2] && played[4] && played[6]) { return 1; } /* top right to bottom left */

    /* no winning diagonal found */
    return 0;
}
