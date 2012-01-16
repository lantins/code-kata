#include "tic_tac_toe_test.h"

void tic_tac_toe_test_suite(void) {
    test_fixture_start();
    run_test(test_can_run_unit_tests);
    run_test(test_calculate_game_state_from_player_moves);
    test_fixture_end();
}

void test_can_run_unit_tests(void) {
    assert_int_equal(1, 1);
}

void test_calculate_game_state_from_player_moves(void) {
    /* game state with zero moves should be `new game` */
    assert_int_equal(0, lp_ttt_play());
}