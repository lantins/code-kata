#include "sudoku.h"

/* FIXME: move game problem data into text files */
static char test_game[kLP_SUDOKU_GAME_CELLS] = {
    5,3,0, 0,7,0, 0,0,0,
    6,0,0, 1,9,5, 0,0,0,
    0,9,8, 0,0,0, 0,6,0,

    8,0,0, 0,6,0, 0,0,3,
    4,0,0, 8,0,3, 0,0,1,
    7,0,0, 0,2,0, 0,0,6,

    0,6,0, 0,0,0, 2,8,0,
    0,0,0, 4,1,9, 0,0,5,
    0,0,0, 0,8,0, 0,7,9
};

static char test_game2[kLP_SUDOKU_GAME_CELLS] = {
    0,0,0, 0,0,0, 0,0,0,
    0,0,0, 0,0,0, 0,0,0,
    0,0,0, 0,0,0, 0,0,0,

    0,0,0, 0,0,0, 0,0,0,
    0,0,0, 0,0,0, 0,0,0,
    0,0,0, 0,0,0, 0,0,0,

    0,0,0, 0,0,0, 0,0,0,
    0,0,0, 0,0,0, 0,0,0,
    0,0,0, 0,0,0, 0,0,0
};


static char game_cell_to_blocks[kLP_SUDOKU_GAME_CELLS] = {
    0,0,0, 1,1,1, 2,2,2,
    0,0,0, 1,1,1, 2,2,2,
    0,0,0, 1,1,1, 2,2,2,

    3,3,3, 4,4,4, 5,5,5,
    3,3,3, 4,4,4, 5,5,5,
    3,3,3, 4,4,4, 5,5,5,

    6,6,6, 7,7,7, 8,8,8,
    6,6,6, 7,7,7, 8,8,8,
    6,6,6, 7,7,7, 8,8,8
};

static char game_block_first_cell[kLP_SUDOKU_GAME_BLOCKS] = {
     0,  3,  6,
    27, 30, 33,
    54, 57, 60
};

void lp_sudoku_init_test_game(char *game) {
    memcpy(game, test_game, sizeof(char) * kLP_SUDOKU_GAME_CELLS);
}

void lp_sudoku_print_game(char *game) {
    size_t row;
    size_t cell;
    size_t row_offset = 0;
    char cell_value = 0;

    for (row = 0; row < kLP_SUDOKU_GAME_ROW_CELLS; ++row) {
        if ((row % 3) == 0) {
            printf("+-------+-------+-------+\n");
        }
        printf("| ");
        row_offset = row * kLP_SUDOKU_GAME_ROW_CELLS;
        for (cell = 0; cell < kLP_SUDOKU_GAME_ROW_CELLS; ++cell) {
            /* get the cells value and print it */
            cell_value = game[row_offset + cell];
            if (cell_value == 0) {
                lp_set_output_colour_red();
                printf(". ");
                lp_reset_output_colour();
            } else {
                printf("%d ", (int)cell_value);
            }

            /* print block divider if required */
            if (((cell + 1) % 3) == 0) {
                printf("| ");
            }
        }
        printf("\n");
    }
    printf("+-------+-------+-------+\n");
}

/* FIXME: this was a copy/paste/edit of lp_sudoku_print_game, make them 1 */
void lp_sudoku_print_solution(char *problem, char *solution) {
    size_t row;
    size_t cell;
    size_t row_offset = 0;
    char cell_value = 0;

    for (row = 0; row < kLP_SUDOKU_GAME_ROW_CELLS; ++row) {
        if ((row % 3) == 0) {
            printf("+-------+-------+-------+\n");
        }
        printf("| ");
        row_offset = row * kLP_SUDOKU_GAME_ROW_CELLS;
        for (cell = 0; cell < kLP_SUDOKU_GAME_ROW_CELLS; ++cell) {
            /* get the cells value and print it */
            cell_value = problem[row_offset + cell];
            if (cell_value == 0) {
                lp_set_output_colour_green();
                cell_value = solution[row_offset + cell];
                printf("%d ", (int)cell_value);
                lp_reset_output_colour();
            } else {
                printf("%d ", (int)cell_value);
            }

            /* print block divider if required */
            if (((cell + 1) % 3) == 0) {
                printf("| ");
            }
        }
        printf("\n");
    }
    printf("+-------+-------+-------+\n");
}

int lp_sudoku_solve_game(char *game) {
    int empty_cell;
    char test_value;

    /* if we have empty cells, the game is not solved */
    if (lp_sudoku_game_is_solved(game)) {
        /* game is now solved! whooo =) */
        return kLP_SUDOKU_RC_SOLVED;
    } else {
        /* find an empty cell */
        empty_cell = lp_sudoku_find_empty_cell(game);

        if (empty_cell == kLP_SUDOKU_ERR_NO_EMPTY_CELLS) {
            return kLP_SUDOKU_ERR_UNSOLVABLE;
        }

        /* try each test value in turn until solved */
        test_value = 1;
        while (test_value <= 9) {
            /* check if test_value is a legal move for this cell */
            if (lp_sudoku_move_is_legal(game, empty_cell, test_value)) {
                /* move is legal, set the cell to the test_value */
                game[empty_cell] = test_value;
                /* check if the game is now solved */
                if (lp_sudoku_solve_game(game) == kLP_SUDOKU_RC_SOLVED) {
                    return kLP_SUDOKU_RC_SOLVED;
                } else {
                    /* reset the cell to empty */
                    game[empty_cell] = 0;
                }
            }

            /* increment test value and try again */
            ++test_value;
        }
    }

    /* if we get here, we were unable to solve the game =( */
    return kLP_SUDOKU_ERR_UNSOLVABLE;
}

int lp_sudoku_find_empty_cell(char *game) {
    size_t cell_index;

    for (cell_index = 0; cell_index < kLP_SUDOKU_GAME_CELLS; ++cell_index) {
        /* if the cell value is zero, its empty */
        if (game[cell_index] == 0) {
            return cell_index;
        }
    }

    return kLP_SUDOKU_ERR_NO_EMPTY_CELLS;
}

int lp_sudoku_game_is_solved(char *game) {
    int rc;
    /* game is solved when we have no empty cells */
    rc = lp_sudoku_find_empty_cell(game);
    if (rc == kLP_SUDOKU_ERR_NO_EMPTY_CELLS) {
        return 1;
    }
    return 0;
}

int lp_sudoku_move_is_legal(char *game, size_t cell_index, char test_value) {
    size_t row;
    size_t column;
    size_t block;

    row = cell_index / kLP_SUDOKU_GAME_ROW_CELLS;
    column = cell_index % kLP_SUDOKU_GAME_ROW_CELLS;
    block = game_cell_to_blocks[cell_index];

    /* for a legal move the integer may not appear twice: */
    /*   - in the same 9x9 game board row or column */
    /*   - in any of the nine 3x3 block subregions of the 9x9 game board */

    /* check if value is repeted in game row */
    if (lp_sudoku_row_already_contains_value(game, row, test_value)) {
        return 0;
    }

    /* check if value is repeted in game column */
    if (lp_sudoku_column_already_contains_value(game, column, test_value)) {
        return 0;
    }

    /* check not repeted in block */
    if (lp_sudoku_block_already_contains_value(game, block, test_value)) {
        return 0;
    }

    /* if we get this far, its a valid move! */
    return 1;
}

int lp_sudoku_row_already_contains_value(char *game, size_t row, char test_value) {
    size_t temp_index;
    size_t offset;

    offset = row * kLP_SUDOKU_GAME_ROW_CELLS;

    /* loop over each value in the row */
    for (temp_index = 0; temp_index < 9; ++temp_index) {
        if (game[offset + temp_index] == test_value) {
            return 1;
        }
    }

    return 0;
}

int lp_sudoku_column_already_contains_value(char *game, size_t column, char test_value) {
    size_t temp_index;
    size_t offset;

    /* loop over each value in the column */
    for (temp_index = 0; temp_index < 9; ++temp_index) {
        offset = kLP_SUDOKU_GAME_ROW_CELLS * temp_index;
        if (game[column + offset] == test_value) {
            return 1;
        }
    }

    return 0;
}

int lp_sudoku_block_already_contains_value(char *game, size_t block, char test_value) {
    size_t block_start;
    size_t block_row;
    size_t block_column;
    size_t offset;

    block_start = game_block_first_cell[block];

    for (block_row = 0; block_row < 3; ++block_row) {
        offset = kLP_SUDOKU_GAME_ROW_CELLS * block_row;

        /* test each column in the blocks row */
        for (block_column = 0; block_column < 3; ++block_column) {
            if (game[block_start + offset + block_column] == test_value) {
                return 1;
            }
        }
    }

    return 0;
}

void lp_set_output_colour_green(void) {
    printf(kLP_TERM_COLOR_GREEN);
}

void lp_set_output_colour_red(void) {
    printf(kLP_TERM_COLOR_RED);
}

void lp_reset_output_colour(void) {
    printf(kLP_TERM_COLOR_RESET);
}
