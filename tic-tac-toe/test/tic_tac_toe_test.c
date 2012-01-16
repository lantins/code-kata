#include "tic_tac_toe_test.h"

void tic_tac_toe_test_suite(void) {
    test_fixture_start();
    run_test(test_can_run_unit_tests);
    run_test(test_zero_moves_means_x_goes_first);
    run_test(test_o_moves_after_x);
    test_fixture_end();
}

void test_can_run_unit_tests(void) {
    assert_int_equal(1, 1);
}

/* game state with zero moves; its X to go first */
void test_zero_moves_means_x_goes_first(void) {
    int moves[kLP_TTT_MAX_MOVES] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    assert_int_equal(kLP_TTT_STATE_TURN_X, lp_ttt_play(moves));
}

void test_o_moves_after_x(void) {
    /* X in top left */
    int moves[kLP_TTT_MAX_MOVES] = { 1, 0, 0, 0, 0, 0, 0, 0, 0 };
    assert_int_equal(kLP_TTT_STATE_TURN_O, lp_ttt_play(moves));
}