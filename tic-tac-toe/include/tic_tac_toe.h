/**
 * @file    tic_tac_toe.h
 * @brief   Tic Tac Toe game engine.
 * @author  Luke Antins
 */

#if !defined(LP_TIC_TAC_TOE_)
#define LP_TIC_TAC_TOE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* cells available on a game board */
#define kLP_TTT_BOARD_CELLS 9

#define kLP_TTT_RC_ILLEGAL_GAME_STATE -1
#define kLP_TTT_RC_NEXT_TURN_X 1
#define kLP_TTT_RC_NEXT_TURN_O 2
#define kLP_TTT_RC_X_WIN 3
#define kLP_TTT_RC_O_WIN 4
#define kLP_TTT_RC_DRAW 5

/* --- function prototypes ------------------------------------------------ */

int lp_ttt_play(int previous_moves[], size_t moves_taken);

int lp_ttt_only_legal_moves(int previous_moves[], size_t moves_taken);
int lp_ttt_win_draw_or_next_turn(int previous_moves[], size_t moves_taken);
int lp_ttt_played_winning_moves(int played[]);
int lp_ttt_played_winning_row(int played[]);
int lp_ttt_played_winning_column(int played[]);
int lp_ttt_played_winning_diagonal(int played[]);

#endif
