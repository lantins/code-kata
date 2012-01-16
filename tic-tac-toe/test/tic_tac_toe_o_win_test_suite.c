#include "tic_tac_toe_o_win_test_suite.h"

/* test suite wiring */
void tic_tac_toe_o_win_test_suite(void) {
    test_fixture_start();

    run_test(test_o_wins_when_played_top_row);
    run_test(test_o_wins_when_played_middle_row);
    run_test(test_o_wins_when_played_bottom_row);

    run_test(test_o_wins_when_played_left_column);
    run_test(test_o_wins_when_played_centre_column);
    run_test(test_o_wins_when_played_right_column);

    run_test(test_o_wins_when_played_diagonal_right);
    run_test(test_o_wins_when_played_diagonal_left);

    test_fixture_end();
}

/* --- unit tests --- */

void test_o_wins_when_played_top_row(void) {
    int moves[6] = { 8, 2, 9, 1, 4, 3 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}

void test_o_wins_when_played_middle_row(void) {
    int moves[6] = { 1, 4, 2, 5, 7, 6 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}

void test_o_wins_when_played_bottom_row(void) {
    int moves[6] = { 1, 7, 3, 8, 5, 9 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}

void test_o_wins_when_played_left_column(void) {
    int moves[6] = { 5, 1, 2, 4, 3, 7 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}

void test_o_wins_when_played_centre_column(void) {
    int moves[6] = { 1, 2, 3, 5, 4, 8 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}

void test_o_wins_when_played_right_column(void) {
    int moves[6] = { 5, 3, 1, 6, 7, 9 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}

void test_o_wins_when_played_diagonal_right(void) {
    int moves[6] = { 7, 5, 2, 1, 6, 9 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}

void test_o_wins_when_played_diagonal_left(void) {
    int moves[6] = { 9, 5, 4, 7, 6, 3 };
    assert_int_equal(kLP_TTT_RC_O_WIN, lp_ttt_play(moves, 6));
}
