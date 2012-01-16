#include "tic_tac_toe_test.h"

void tic_tac_toe_test_suite(void) {
    test_fixture_start();
    run_test(test_can_run_unit_tests);
    run_test(test_zero_moves_means_x_goes_first);
    run_test(test_o_moves_after_x);
    run_test(test_x_moves_after_o);
    run_test(test_can_detect_an_illegal_state_top_left);
    run_test(test_can_detect_an_illegal_state_top_right);
    run_test(test_can_detect_an_illegal_state_after_several_moves);
    test_fixture_end();
}

void test_can_run_unit_tests(void) {
    assert_int_equal(1, 1);
}

/* game state with zero moves; its X to go first */
void test_zero_moves_means_x_goes_first(void) {
    int moves[1];
    assert_int_equal(kLP_TTT_TURN_X, lp_ttt_play(moves, 0));
}

void test_o_moves_after_x(void) {
    /* X in bottom right */
    int moves[1] = { 9 };
    assert_int_equal(kLP_TTT_TURN_O, lp_ttt_play(moves, 1));
}

void test_x_moves_after_o(void) {
    /* X in top left, O in top middle */
    int moves[2] = { 1, 2 };
    assert_int_equal(kLP_TTT_TURN_X, lp_ttt_play(moves, 2));
}

void test_can_detect_an_illegal_state_top_left(void) {
    /* both X and O in top left */
    int moves[2] = { 1, 1 };

    assert_int_equal(kLP_TTT_ILLEGAL_GAME_STATE, lp_ttt_play(moves, 2));
}

void test_can_detect_an_illegal_state_top_right(void) {
    /* both X and O in top right */
    int moves[2] = { 3, 3 };

    assert_int_equal(kLP_TTT_ILLEGAL_GAME_STATE, lp_ttt_play(moves, 2));
}

void test_can_detect_an_illegal_state_after_several_moves(void) {
    /* both X and O in bottom right */
    int moves[5] = { 4, 9, 3, 2, 9 };

    assert_int_equal(kLP_TTT_ILLEGAL_GAME_STATE, lp_ttt_play(moves, 5));
}
