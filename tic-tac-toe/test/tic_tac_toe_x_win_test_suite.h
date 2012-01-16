#if !defined(TIC_TAC_TOE_X_WIN_TEST_SUITE_H_)
#define TIC_TAC_TOE_X_WIN_TEST_SUITE_H_

#include <stdio.h>
#include <string.h>

#include "seatest.h"
#include "../include/tic_tac_toe.h"

/* test suites */
void tic_tac_toe_x_win_test_suite(void);

/* unit tests */
void test_x_wins_when_played_top_row(void);
void test_x_wins_when_played_middle_row(void);
void test_x_wins_when_played_bottom_row(void);

void test_x_wins_when_played_left_column(void);
void test_x_wins_when_played_centre_column(void);
void test_x_wins_when_played_right_column(void);

void test_x_wins_when_played_diagonal_right(void);
void test_x_wins_when_played_diagonal_left(void);

#endif
