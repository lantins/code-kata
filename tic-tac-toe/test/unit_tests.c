/**
 * @file    unit_tests.c
 * @brief   Main entry point for unit tests, test runner.
 * @author  Luke Antins
 */

#include "seatest.h"

#include "tic_tac_toe_test.h"

int main(void) {
    int rc = 0;

    /* run all tests */
    rc = run_tests(tic_tac_toe_test_suite);

    if (rc == 0) {
        /* oh noes! one or more tests failed :( */
        return 1;
    }
    /* all tests successful =) */
    return 0;
}