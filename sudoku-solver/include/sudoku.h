/**
 * @file    sudoku.h
 * @brief   Solving algorithm for sudoku game
 * @author  Luke Antins
 */

#if !defined(LP_SUDOKU_)
#define LP_SUDOKU_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define kLP_TERM_COLOR_RESET   "\033[0m"
#define kLP_TERM_COLOR_GREEN   "\033[32m"
#define kLP_TERM_COLOR_RED     "\033[31m"

#define kLP_SUDOKU_GAME_CELLS 81
#define kLP_SUDOKU_GAME_BLOCKS 9
#define kLP_SUDOKU_GAME_ROW_CELLS 9

#define kLP_SUDOKU_RC_SOLVED 1
#define kLP_SUDOKU_ERR_UNSOLVABLE -1
#define kLP_SUDOKU_ERR_NO_EMPTY_CELLS -1

/* --- function prototypes ------------------------------------------------ */

void lp_sudoku_init_test_game(char *game);
void lp_sudoku_print_game(char *game);
int lp_sudoku_solve_game(char *game);
int lp_sudoku_find_empty_cell(char *game);
int lp_sudoku_game_is_solved(char *game);
int lp_sudoku_move_is_legal(char *game, size_t cell_index, char test_value);

int lp_sudoku_row_already_contains_value(char *game, size_t row, char test_value);
int lp_sudoku_column_already_contains_value(char *game, size_t column, char test_value);
int lp_sudoku_block_already_contains_value(char *game, size_t block, char test_value);

void lp_set_output_colour_green(void);
void lp_set_output_colour_red(void);
void lp_reset_output_colour(void);

#endif
