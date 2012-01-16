#if !defined(TIC_TAC_TOE_TEST_H_)
#define TIC_TAC_TOE_TEST_H_

#include <stdio.h>
#include <string.h>

#include "seatest.h"
#include "../include/tic_tac_toe.h"

/* test suite */
void tic_tac_toe_test_suite(void);

/* unit tests */
void test_can_run_unit_tests(void);
void test_zero_moves_means_x_goes_first(void);
void test_o_moves_after_x(void);
void test_x_moves_after_o(void);

#endif
