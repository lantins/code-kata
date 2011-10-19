/**
 * @file    main.c
 * @brief   Sudoku solver
 * @author  Luke Antins
 */

#include "sudoku.h"

int main(void) {
    char problem[kLP_SUDOKU_GAME_CELLS];
    char game[kLP_SUDOKU_GAME_CELLS];

    /* load up our test game to solve */
    lp_sudoku_init_test_game(problem);
    lp_sudoku_init_test_game(game);

    /* display the game problem (before solving) */
    printf("\nGAME PROBLEM\n\n");
    lp_sudoku_print_game(problem);

    /* attempt to solve the game */
    if (lp_sudoku_solve_game(game) == kLP_SUDOKU_RC_SOLVED) {
        /* display the solved game */
        printf("\nGAME SOLUTION\n\n");
        lp_sudoku_print_solution(problem, game);
    } else {
        printf("ERROR: UNABLE TO FIND SOLUTION\n");
    }

    return 0;
}