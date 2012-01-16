#include "tic_tac_toe_test.h"

void tic_tac_toe_test_suite(void) {
    test_fixture_start();
    run_test(test_first);
    test_fixture_end();
}

void test_first(void) {
    assert_int_equal(0, 1);
}