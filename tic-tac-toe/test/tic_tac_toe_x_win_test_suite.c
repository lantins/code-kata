#include "tic_tac_toe_x_win_test_suite.h"

/* test suite wiring */
void tic_tac_toe_x_win_test_suite(void) {
    test_fixture_start();

    run_test(test_x_wins_when_played_top_row);
    run_test(test_x_wins_when_played_middle_row);
    run_test(test_x_wins_when_played_bottom_row);
    run_test(test_x_wins_when_played_left_column);
    run_test(test_x_wins_when_played_centre_column);
    run_test(test_x_wins_when_played_right_column);
    run_test(test_x_wins_when_played_diagonal_right);
    run_test(test_x_wins_when_played_diagonal_left);

    test_fixture_end();
}

/* --- unit tests --- */

void test_x_wins_when_played_top_row(void) {
    int moves[5] = { 2, 9, 1, 4, 3 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 5));
}

void test_x_wins_when_played_middle_row(void) {
    int moves[7] = { 5, 1, 4, 3, 8, 7, 6 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 7));
}

void test_x_wins_when_played_bottom_row(void) {
    int moves[5] = { 7, 4, 8, 5, 9 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 5));
}

void test_x_wins_when_played_left_column(void) {
    int moves[5] = { 1, 5, 4, 9, 7 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 5));
}

void test_x_wins_when_played_centre_column(void) {
    int moves[5] = { 8, 9, 5, 1, 2 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 5));
}

void test_x_wins_when_played_right_column(void) {
    int moves[5] = { 3, 4, 9, 5, 6 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 5));
}

void test_x_wins_when_played_diagonal_right(void) {
    int moves[5] = { 5, 2, 1, 4, 9 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 5));
}

void test_x_wins_when_played_diagonal_left(void) {
    int moves[5] = { 5, 4, 7, 6, 3 };
    assert_int_equal(kLP_TTT_RC_X_WIN, lp_ttt_play(moves, 5));
}
