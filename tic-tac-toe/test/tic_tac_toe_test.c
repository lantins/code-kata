#include "tic_tac_toe_test.h"

void tic_tac_toe_test_suite(void) {
    test_fixture_start();
    run_test(test_can_run_unit_tests);
    run_test(test_zero_moves_means_new_game);
    test_fixture_end();
}

void test_can_run_unit_tests(void) {
    assert_int_equal(1, 1);
}

void test_zero_moves_means_new_game(void) {
    /* game state with zero moves should be `new game` */
    assert_int_equal(0, lp_ttt_play());
}