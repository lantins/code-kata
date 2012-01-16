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

/* max moves possible per game */
#define kLP_TTT_MAX_MOVES 9

#define kLP_TTT_ILLEGAL_GAME_STATE -1
#define kLP_TTT_TURN_X 1
#define kLP_TTT_TURN_O 2

/* --- function prototypes ------------------------------------------------ */

int lp_ttt_play(int previous_moves[], size_t moves_taken);
int lp_ttt_only_legal_moves(int previous_moves[], size_t moves_taken);

#endif
