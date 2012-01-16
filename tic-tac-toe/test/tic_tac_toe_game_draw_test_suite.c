#include "tic_tac_toe_game_draw_test_suite.h"

/* test suite wiring */
void tic_tac_toe_game_draw_test_suite(void) {
    test_fixture_start();

    run_test(test_game_draw);

    test_fixture_end();
}

/* --- unit tests --- */

void test_game_draw(void) {
    int moves[9] = { 3, 2, 5, 1, 4, 6, 8, 7, 9 };
    assert_int_equal(kLP_TTT_RC_DRAW, lp_ttt_play(moves, 9));
}
