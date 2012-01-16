/**
 * @file    unit_tests.c
 * @brief   Main entry point for unit tests, test runner.
 * @author  Luke Antins
 */

#include "seatest.h"

#include "tic_tac_toe_game_draw_test_suite.h"
#include "tic_tac_toe_illegal_state_test_suite.h"
#include "tic_tac_toe_next_turn_test_suite.h"
#include "tic_tac_toe_o_win_test_suite.h"
#include "tic_tac_toe_x_win_test_suite.h"

void all_test_suites(void);

void all_test_suites(void) {
    tic_tac_toe_game_draw_test_suite();
    tic_tac_toe_illegal_state_test_suite();
    tic_tac_toe_next_turn_test_suite();
    tic_tac_toe_o_win_test_suite();
    tic_tac_toe_x_win_test_suite();
}

int main(void) {
    int rc = 0;

    /* run all tests */
    rc = run_tests(all_test_suites);

    if (rc == 0) {
        /* oh noes! one or more tests failed :( */
        return 1;
    }
    /* all tests successful =) */
    return 0;
}