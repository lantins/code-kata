#include "tic_tac_toe_next_turn_test_suite.h"

/* test suite wiring */
void tic_tac_toe_next_turn_test_suite(void) {
    test_fixture_start();

    run_test(test_zero_moves_means_x_goes_first);
    run_test(test_o_moves_after_x);
    run_test(test_x_moves_after_o);
    run_test(test_o_moves_on_turn_4);
    run_test(test_x_moves_on_turn_7);

    test_fixture_end();
}

/* --- unit tests --- */

void test_zero_moves_means_x_goes_first(void) {
    int moves[1];
    assert_int_equal(kLP_TTT_RC_NEXT_TURN_X, lp_ttt_play(moves, 0));
}

void test_o_moves_after_x(void) {
    /* X in bottom right */
    int moves[1] = { 9 };
    assert_int_equal(kLP_TTT_RC_NEXT_TURN_O, lp_ttt_play(moves, 1));
}

void test_x_moves_after_o(void) {
    /* X in top left, O in top middle */
    int moves[2] = { 1, 2 };
    assert_int_equal(kLP_TTT_RC_NEXT_TURN_X, lp_ttt_play(moves, 2));
}

void test_o_moves_on_turn_4(void) {
    int moves[3] = { 1, 2, 3 };
    assert_int_equal(kLP_TTT_RC_NEXT_TURN_O, lp_ttt_play(moves, 3));
}

void test_x_moves_on_turn_7(void) {
    int moves[6] = { 1, 2, 3, 4, 5, 6 };
    assert_int_equal(kLP_TTT_RC_NEXT_TURN_X, lp_ttt_play(moves, 6));
}
