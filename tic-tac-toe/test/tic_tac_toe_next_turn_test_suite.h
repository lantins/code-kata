#if !defined(TIC_TAC_TOE_NEXT_TURN_TEST_SUITE_H_)
#define TIC_TAC_TOE_NEXT_TURN_TEST_SUITE_H_

#include <stdio.h>
#include <string.h>

#include "seatest.h"
#include "../include/tic_tac_toe.h"

/* test suites */
void tic_tac_toe_next_turn_test_suite(void);

/* unit tests */
void test_zero_moves_means_x_goes_first(void);
void test_o_moves_after_x(void);
void test_x_moves_after_o(void);
void test_o_moves_on_turn_4(void);
void test_x_moves_on_turn_7(void);

#endif
