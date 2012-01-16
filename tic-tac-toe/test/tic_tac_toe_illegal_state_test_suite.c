#include "tic_tac_toe_illegal_state_test_suite.h"

/* test suite wiring */
void tic_tac_toe_illegal_state_test_suite(void) {
    test_fixture_start();

    run_test(test_can_detect_an_illegal_state_top_left);
    run_test(test_can_detect_an_illegal_state_top_right);
    run_test(test_can_detect_an_illegal_state_after_several_moves);

    test_fixture_end();
}

/* --- unit tests --- */

void test_can_detect_an_illegal_state_top_left(void) {
    /* both X and O in top left */
    int moves[2] = { 1, 1 };
    assert_int_equal(kLP_TTT_RC_ILLEGAL_GAME_STATE, lp_ttt_play(moves, 2));
}

void test_can_detect_an_illegal_state_top_right(void) {
    /* both X and O in top right */
    int moves[2] = { 3, 3 };
    assert_int_equal(kLP_TTT_RC_ILLEGAL_GAME_STATE, lp_ttt_play(moves, 2));
}

void test_can_detect_an_illegal_state_after_several_moves(void) {
    int moves[5] = { 1, 9, 3, 8, 9 };
    assert_int_equal(kLP_TTT_RC_ILLEGAL_GAME_STATE, lp_ttt_play(moves, 5));
}
